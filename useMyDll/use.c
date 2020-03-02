#include <stdio.h>

#pragma comment(lib, "mydll.lib")

int myAdd(int a, int b);
int mySub(int a, int b);

int main() {
	int a = 5, b = 6;
	printf("调用dll函数myAdd的函数结果：myAdd(%d, %d) = %d\n", a, b, myAdd(a, b));
	printf("调用dll函数mySub的函数结果：mySub(%d, %d) = %d", a, b, mySub(a, b));
	return 0;
}