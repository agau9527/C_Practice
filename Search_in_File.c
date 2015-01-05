#include <stdio.h>
#include <stdlib.h>

int Search_in_File(char *fname, char *str)
{
	FILE *fp;
	int line_num = 1;
	int find_result = 0, find_line=0;
	char temp[512];

	if((fp = fopen(fname, "r")) == NULL){
		return(-1);
	}
	while(fgets(temp, 512, fp) != NULL){
		if((strstr(temp, str)) != NULL){
			//printf("A match found on line: %d\n", line_num);
			//printf("\n%s\n", temp);
			find_result++;
			find_line = line_num;
		}
		line_num++;
	}
	if(fp)
		fclose(fp);

	//  if(find_result == 0)
	//      return 0;

	return find_line;
}

