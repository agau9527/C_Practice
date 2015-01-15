#include <stdio.h>
#include <string.h>

void main()
{
	char str2[] = "112112desf.213 @1.1.1.2";  
	char *buf;  
	char *token;  
	buf = str2;

	strsep(&buf, "@");
	token = strsep(&buf, "@");
	printf("%s\n", token);

}
