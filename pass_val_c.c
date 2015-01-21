#include <stdio.h>
#include <stdlib.h>


int g_Test = 999;
void foo1(int *n)
{
	//n is formal parameter(parameter)
	n = &g_Test;
	*n = 888;
}

void foo2(int *n)
{
	//although n is a replica of num1's address
	//but change the value to the address n point to
	//would change num1 (same address)
	*n = 333;
}

int main()
{
	int num1 = 100;
	int num2 = 200;
	int *pNum1 = &num1;
	foo1(pNum1);
	foo1(&num2);
	//100 , 200 , 800
	//It's pass by value, the value is pointer
	//Pass by value: replica of actual parameter(argument)
	//Here, *pNum1, num2, g_Test are actual parameter
	printf("%d %d %d\n", *pNum1, num2, g_Test);
	
	foo2(&num1);
	printf("%d\n", num1);

	exit(0);
}
