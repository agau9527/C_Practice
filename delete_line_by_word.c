#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fileptr1, *fileptr2;
	char filename[40],keyWord[64];
	char ch;
	int delete_line, temp = 1;

	printf("Enter file name: ");
	scanf("%s", filename);
	//open file in read mode
	fileptr1 = fopen(filename, "r");
	ch = fgetc(fileptr1);
	
	while(ch != EOF)
	{
		printf("%c", ch);
		ch = fgetc(fileptr1);
	}

	//rewind
	rewind(fileptr1);
	//printf(" \nEnter line number of the line to be deleted: ");
	//scanf("%d", &delete_line);
	printf("\nEnter the key word and delete the line.");
	scanf("%s", keyWord);
	delete_line = Search_in_File(filename,keyWord);

	//open new file in write mode
	fileptr2 = fopen("replica.c", "w");
	ch = fgetc(fileptr1);
	while(ch != EOF)
	{
		if(ch == '\n')
			temp++;
		//except the line to be deleted
		if(temp != delete_line)
		{
			//copy all lines in file replica.c
			fputc(ch, fileptr2);
		}
		ch = fgetc(fileptr1);
	}
	fclose(fileptr1);
	fclose(fileptr2);
	remove(filename);
	//rename the file replica.c to original name
	rename("replica.c", filename);
	printf("\nThe contents of file after being modified are as follows:\n");
	fileptr1 = fopen(filename, "r");
	ch = fgetc(fileptr1);
	while(ch != EOF)
	{
		printf("%c", ch);
		ch = fgetc(fileptr1);
	}
	fclose(fileptr1);
	return 0;
}
int Search_in_File(char *fname, char *str)
{
	FILE *fp;
	int line_num = 1, line_at;
	int find_result = 0;
	char temp[512];

	if((fp = fopen(fname, "r")) == NULL){
		return(-1);
	}
	while(fgets(temp, 512, fp) != NULL){
		if((strstr(temp, str)) != NULL){
			//printf("A match found on line: %d\n", line_num);
			//printf("\n%s\n", temp);
			find_result++;
			line_at = line_num;
		}
		line_num++;
	}
	if(fp)
		fclose(fp);

	if(find_result == 0)
		return 0;

	return line_at;
}
