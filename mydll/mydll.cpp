#include <iostream>
#include <stdlib.h>
#include "mydll.h"
using namespace std;

#pragma comment(lib, "../x64/Debug/mydll2.lib")

typedef int(__stdcall *fAnalyzerDataCallBack)(void* pAlarmInfo, unsigned char *pBuffer, unsigned long dwBufSize);
int __stdcall CLIENT_RealLoadPictureEx(int lLoginID, int nChannelID, fAnalyzerDataCallBack cbAnalyzerData);


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

void getIntArray(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i + 2;
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