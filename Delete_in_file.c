#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Delete_in_File(char *filename,int delete_line)
{
	char file_path [512], copy_file[1024];
	char *ptr;
	ptr = realpath(filename, file_path);
	snprintf(copy_file, sizeof(copy_file), "%s_copy", ptr);

	FILE *fileptr1, *fileptr2;
	char ch;
	int temp = 1;

	//open file in read mode
	fileptr1 = fopen(filename, "r");
	ch = fgetc(fileptr1);
	//open new file in write mode
	fileptr2 = fopen(copy_file, "w");
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
	rename(copy_file, filename);
	return 0;
}
