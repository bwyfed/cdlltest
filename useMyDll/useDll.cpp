#include <stdio.h>
#include "useMyDll.h"
#pragma comment(lib, "../x64/Debug/mydll.lib")


int main() {
	int a = 5, b = 6;
	unsigned char *arr = nullptr;
	int size = 10;
	unsigned char *myarr = myAdd(a, b, arr, size);
	printf("����mydll����myAdd�ĺ��������\n");
	printf("start print myarr:\n");
	for (int i = 0; i < size; i++) {
		printf("%c,", myarr[i]);
	}
	printf("����mydll����mySub�ĺ��������mySub(%d, %d) = %d", a, b, mySub(a, b));
	return 0;
}