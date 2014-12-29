#include <stdio.h>

void main()
{
	int i[]={10,20,30,40,50};
	int *pa[]={i,i+2,i+1,i+4,i+3};
	int **p2=pa;

	printf("%p\n",&i[0]);
	printf("%p\n",&pa[0]);

	printf("%p\n",&pa[0]);

	printf("%p\n",p2);























}
