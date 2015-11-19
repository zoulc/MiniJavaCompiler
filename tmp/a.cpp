#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cstdio>

int main()
{
	int *a=(int*)malloc(sizeof(int)*10);
	a[0]=1;
	a[1]=2;
	printf("%d\n",a[0]+a[1]);
	return 0;
}
