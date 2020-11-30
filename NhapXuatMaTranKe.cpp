#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10 
#define inputfile "Test1_01.txt"
typedef struct GRAPH{
	int n;
	int a[MAX][MAX];
}DOTHI; 

int NhapDoThi (char TenFile[100], DOTHI &g)
{	
	FILE*f;
	f=fopen(TenFile,"rt");
	if(f==NULL) 
	{
		printf("khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	int i,j;
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
		fscanf(f,"%d",&g.a[i][j]);
	}
	fclose(f);
	return 1;
} 
 
 void XuatMaTranKe(DOTHI g)
 {
 	printf("So dinh cua do thi la %d\n",g.n);
 	printf("Ma tran ke cua do thi la\n");
 	for(int i =0;i<g.n;i++)
 	{
 		printf("\t");
 		for (int j=0; j<g.n;j++)
 		printf ("%5d",g.a[i][j]);
 		printf("\n");	
	 }
 	 
 }
int main ()
{	
	DOTHI g;	
	NhapDoThi(inputfile,g);
	XuatMaTranKe(g);
	return 0;
}
