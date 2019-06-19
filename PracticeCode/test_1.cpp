#include <iostream>

int main()
{
    int i,j,k,a=3,b=2;
    i=(--a==b++)?--a:++b;
    j=a++;k=b;
    printf("i=%d,j=%d,k=%d\n",i,j,k);

    return 0;
}