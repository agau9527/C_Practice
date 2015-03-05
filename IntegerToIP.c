#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void print_ip(int ip)
{
	int idx = 0;
	unsigned char bytes[4];
	
	bytes[3] = ip & 0xFF;
	bytes[2] = (ip >> 8) & 0xFF;
	bytes[1] = (ip >> 16) & 0xFF;
	bytes[0] = (ip >> 24) & 0xFF;
	printf("%d.%d.%d.%d\n", bytes[0], bytes[1], bytes[2], bytes[3]);        
}
void po(int *ip)
{
	//ip is dest's addr, *ip is dest's value
	
	int x = 2, y;
	*ip = x;
	y  = *ip + 1;   
	printf("%d %u %d %u %d %u\n", x, &x, *ip, ip, y, &y);
	//2 1366711356 2 1366711404 3 1366711352
}

int main()
{
	unsigned int tip = 174477627;
	print_ip(tip);
	return 0;
}
