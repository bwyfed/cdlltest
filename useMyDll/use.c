#include <stdio.h>

#pragma comment(lib, "mydll.lib")

int myAdd(int a, int b);
int mySub(int a, int b);

int main() {
	int a = 5, b = 6;
	printf("����dll����myAdd�ĺ��������myAdd(%d, %d) = %d\n", a, b, myAdd(a, b));
	printf("����dll����mySub�ĺ��������mySub(%d, %d) = %d", a, b, mySub(a, b));
	return 0;
}