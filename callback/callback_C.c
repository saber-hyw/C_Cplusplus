#include <stdio.h>

// typedef
typedef int (*CALLBACK)(int, int);

//回调函数
int ADD(CALLBACK pCallback, int a, int b) {
	return (*pCallback)(a,b); //此处回调add函数...
}

//普通函数
int add(int a, int b) {
	return a + b;
}
 
int main(void) {
	printf("%d\n",add(1,2));
	printf("%d\n",ADD(add,1,2));
	return 0;
}  