#include <iostream>
#include <stdlib.h>
#include "mydll.h"
using namespace std;

#pragma comment(lib, "../x64/Debug/mydll2.lib")

typedef int(__stdcall *fAnalyzerDataCallBack)(void* pAlarmInfo, unsigned char *pBuffer, unsigned long dwBufSize);
int __stdcall CLIENT_RealLoadPictureEx(int lLoginID, int nChannelID, fAnalyzerDataCallBack cbAnalyzerData);

// typedef int(__stdcall *fTestCallback)(unsigned char * pBuffer, int bufSize);

unsigned char* gArr = nullptr;
int gSize = 0;

int __stdcall callback(unsigned char * pBuffer, int bufSize) {
	cout << "in callback, pBuffer:" << pBuffer << ",bufSize=" << bufSize << endl;
	for (int i = 0; i < bufSize; i++) {
		cout << pBuffer[i] << ",";
	}
	gArr = pBuffer;
	gSize = bufSize;
	cout << endl;
	return 200;
}

int __stdcall AnylyzerDataCallBack(void* pAlarmInfo, unsigned char *pBuffer, unsigned long dwBufSize) {
	cout << "in AnylyzerDataCallBack" << endl;
	cout << "pAlarmInfo:" << static_cast<int *>(pAlarmInfo) << endl;
	cout << "pBuffer:" << pBuffer << ", pBuffer->" << *pBuffer << endl;
	for (int i = 0; i < dwBufSize; i++) {
		cout << pBuffer[i] << ",";
	}
	return 0;
}

__declspec(dllexport)
unsigned char * myAdd(int a, int b, unsigned char *arr, int size) {
	cout << "in myAdd, a="<<a<<",b="<< b << endl;
	CLIENT_RealLoadPictureEx(12345, 54321, AnylyzerDataCallBack);
	// arr 指针，在外已经分配了空间了，可以直接赋值
//	arr = new unsigned char[size];
	for (int i = 0; i < size; i++) {
		arr[i] = 'c' + i;
	}
	// 试图使用以下的类型转换来获取int数组的方式，是可行的吗？
	// 经测试是不可行的
	/*
	int *intArr = reinterpret_cast<int *>(arr);
	for (int i = 0; i < size/4; i++) {
		intArr[i] = i + 2;
	}
	*/
	return arr;
}
__declspec(dllexport)
void getCharArray(unsigned char *arr, int size) {
	cout << "in getCharArray, size=" << size << endl;
	for (int i = 0; i < size; i++) {
		arr[i] = 'a' + i;
	}
	return;
}

__declspec(dllexport)
void getIntArray(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i + 2;
	}
}
// 模拟CLIENT_RealLoadPictureEx的内部实现
int invokeCallback(int a, int b, fTestCallback cb) {
	unsigned char * arr = nullptr;
	int size = 0;
	int result = 0;
	if (a > b) {
		arr = new unsigned char[a];
		for (int i = 0; i < a; i++) {
			arr[i] = 'a' + i;
		}
		result = cb(arr, a);
	}
	else {
		arr = new unsigned char[b];
		for (int i = 0; i < b; i++) {
			arr[i] = 'z' - i;
		}
		result = cb(arr, b);
	}
	return result;
}

// 外面要调用的函数
__declspec(dllexport)
void testInvokeCallback(int a, int b, unsigned char *out, int* size) {
	cout << "in testInvokeCallback, a=" << a << ",b="<<b << endl;
	int invokeRes = invokeCallback(a, b, callback); // invokeCallback == CLIENT_RealLoadPictureEx
	if (invokeRes == 200) {
//		out = gArr;
		*size = gSize;
		for (int i = 0; i < *size; i++) {
			out[i] = gArr[i];
		}
	}
}
__declspec(dllexport)
int mySub(int a, int b) {
	cout << "in mySub" << endl;
	return a - b;
}

__declspec(dllexport)
void gettimeofday(struct timeval* tv) {
	cout << "gettimeofday, c++:" << endl;
	tv->tv_sec = 100;
	tv->tv_usec = 200;
	tv->stTT.aa = 400;
	tv->stTT.bb = 500;
	cout << tv->tv_sec<<","<< tv->tv_usec <<",tv->stTT.aa:"<< tv->stTT.aa<<",tv->stTT.bb:"<< tv->stTT.bb<< endl;
	return;
}