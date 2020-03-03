#pragma once
extern "C" _declspec(dllexport) unsigned char * myAdd(int a, int b, unsigned char *arr, int size);
extern "C" _declspec(dllexport) int mySub(int a, int b);

typedef struct tagTT {
	int aa;
	int bb;
} tt;
extern "C" _declspec(dllexport) struct timeval {
	int  tv_sec;   /* seconds since Jan. 1, 1970 */
	int  tv_usec;  /* and microseconds */
	tt stTT;
};

extern "C" _declspec(dllexport) void gettimeofday(struct timeval* tv);