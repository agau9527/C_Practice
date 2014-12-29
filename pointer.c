#include <stdio.h>
#include <unistd.h>

void main()
{

//	printf("Star to sleep~\n");
//	sleep(100);
//	printf("Wake up wwwwwwww~\n");


	char *str="Happy";
	char *str1=str;
	printf("*str=\"Happy\" \n");
	printf("*str1=str");

	//"Happy"
	printf("str = %s\n",str);
    //'H'                       
    printf("*str = %c\n",*str);
    //Addr of Happy                       
    printf("Addr of Happy is str = %p\n",str);
	//Addr of str
	printf("Addr of str is &str = %p\n",&str);


	//"Happy"
    printf("str1 = %s\n",str1);
    //'H'                       
	printf("*str1 = %c\n",*str);               //printf("%s")
    //Addr of Happy                       
    printf("Addr of Happy is str = %p\n",str);
    //Addr of str
    printf("Addr of str is &str = %p\n",&str);
}
