#include <stdio.h>
#include "useMyDll.h"
#pragma comment(lib, "../x64/Debug/mydll.lib")


int main() {
	int a = 5, b = 6;
	unsigned char *arr = nullptr;
	int size = 10;
	arr = new unsigned char[size];
	unsigned char *myarr = myAdd(a, b, arr, size);
	printf("调用mydll函数myAdd的函数结果：\n");
	printf("start print myarr:\n");
	for (int i = 0; i < size; i++) {
		printf("%c,", myarr[i]);
	}
	printf("调用mydll函数mySub的函数结果：mySub(%d, %d) = %d", a, b, mySub(a, b));
	struct timeval tv;
	printf("调用mydll函数gettimeofday的函数结果：\n");
	gettimeofday(&tv);
	printf("tv->tv_sec:%d, tv->tv_usec: %d, tv->stTT.aa: %d, tv->stTT.bb: %d", tv.tv_sec, tv.tv_usec, tv.stTT.aa, tv.stTT.bb);

	return 0;
}