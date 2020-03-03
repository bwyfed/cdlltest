#pragma once

#ifndef MAIN_H
#define MAIN_H

typedef int(__stdcall *fTestCallback)(unsigned char * pBuffer, int bufSize);
extern "C" _declspec(dllexport) unsigned char * myAdd(int a, int b, unsigned char *arr, int size);
extern "C" _declspec(dllexport) void getCharArray(unsigned char *arr, int size);
extern "C" _declspec(dllexport) void getIntArray(int *arr, int size);
int invokeCallback(int a, int b, fTestCallback cb);
extern "C" _declspec(dllexport) void testInvokeCallback(int a, int b, unsigned char *out, int* size);
extern "C" _declspec(dllexport) int mySub(int a, int b);

__declspec(dllexport) typedef struct tagTT {
	int aa;
	int bb;
} tt;
extern "C" _declspec(dllexport) struct timeval {
	int tv_sec;   /* seconds since Jan. 1, 1970 */
	int tv_usec;  /* and microseconds */
	tt stTT;
};
extern "C" _declspec(dllexport) void gettimeofday(struct timeval* tv);
#endif //PCH_H
