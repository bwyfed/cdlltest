#include <iostream>
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
	arr = new unsigned char[size];
	for (int i = 0; i < size; i++) {
		arr[i] = 'c' + i;
	}
	return arr;
}

__declspec(dllexport)
int mySub(int a, int b) {
	cout << "in mySub" << endl;
	return a - b;
}