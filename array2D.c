#include<stdio.h>
#include<stdlib.h>

void allocte_2D_int_array(int***int_array,int index1,int index2,int default_value)
{
	int **tmp;
    int i,j;
	//allocte all needed memory
	*int_array = (int**)malloc(index1*sizeof(int*)+index1*index2*sizeof(int));
	//create linker
	tmp = *int_array;
	for(i=0;i<index1;i++)
	{
		tmp[i]=(int*)(tmp+(index1+index2*i));
	}
	//default value
	for(i=0; i<index1; i++)
	{
		for(j=0; j<index2; j++)
			tmp[i][j]= default_value;
	}
}

void allocte_3D_int_array(int****int_array,int index1,int index2,int index3)
{
	int ***array,***pa,**p;
	int i,j;
	//allocte all needed memory
	array = (int***)malloc(index1*sizeof(int**)+index1*index2*sizeof(int*)+index1*index2*index3*sizeof(int));
	//create linker
	pa = array;
	for(i=0;i<index1;i++)  
		array[i] = (int**)(pa+index1+index2*i);//ok
	
	for(i=0;i<index1;i++)
	{
		p=array[i];
		for(j=0;j<index2;j++)
		{
			*p = (int*)(pa+index1+index1*index2+(i*index2*index3+j*index3));//ok
			p++;
		}
	}
	*int_array = array; 
}

int main()
{
	int **A,**B;
	int ii,ant,ant_num=3,cal_size=10;
	//Tx_Cal memory allocate
	allocte_2D_int_array(&A,ant_num,cal_size,-1);
	for(ant=0;ant<ant_num;ant++)
	{
		for(ii=0;ii<cal_size;ii++)
			printf("%d",A[ant][ii]);
		printf("\n");
	}
	free(A);
	printf("**************************************\n");
	allocte_2D_int_array(&B,ant_num,cal_size,-9);
	for(ant=0;ant<ant_num;ant++)
	{
		for(ii=0;ii<cal_size;ii++)
			printf("%d",B[ant][ii]);
		printf("\n");
	}
	free(B);
	printf("\nTx_Cal allocate memory success!\n");
	printf("Jason's small tool code.\n");
	system("pause");
}
