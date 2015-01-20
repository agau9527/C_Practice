#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char *a[]={"I", "LOVE", "C", "PROGRAMMING"}; 
	char buf[1024] = {0};
	int i, len = sizeof(a)/sizeof(a[0]);
	for (i = 0; i < len; i++) {
		strcat(buf, a[i]);
		if (i < len - 1)
			strcat(buf, " ");
	}
	printf("[%s]\n", buf);
	return 0;
}

//using char **a;
//int main(int argc, char* argv[]) {
//	char *a[] = {"I", "LOVE", "C", "PROGRAMMING", NULL}; 
//	char buf[1024] = {0}, **p = a;
//	while (*p) {
//		strcat(buf, *p);
//		if (*p && *(p + 1))
//			strcat(buf, " ");
//		p++;
//	}
//	printf("[%s]\n", buf);
//	return 0;
//}
