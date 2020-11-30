#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10 
#define inputfile "Test1_03.txt"
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
 
int ktDuongCheo (DOTHI g)
{
	for(int i=0;i<g.n;i++)
		if (g.a[i][i] !=0 ) return -1;	
	return 0;
}
int ktVoHuong (DOTHI g)
{
	for(int i=0;i<g.n;i++)
	{
		for(int j=0;j<g.n;j++)
			if (g.a[j][i] !=g.a[i][j] ) return -1;
	}
	return 0;
}

void SoBacCuaMT (DOTHI g)
{ 
	if(ktVoHuong(g)==0)
	for (int k =0 ; k<g.n;k++)
	{
		int sum=0;
		for(int i=0;i<g.n;i++)
		{		
			if(g.a[k][i]!=0) sum++;
		}
		printf ("bac cua dinh %d la %d\n",k,sum);
	}
	else
		
	for (int k =0 ; k<g.n;k++)
	{
		int sumin=0; int sumout =0;
		for(int i=0;i<g.n;i++)
		{		
			if(g.a[k][i]!=0) sumout++;
			if(g.a[i][k]!=0) sumin++;
		}
		printf ("dinh %d bac ra la %d bac vao la %d\n",k,sumout,sumin);
	}
}

int main ()
{	
	DOTHI g;	
	NhapDoThi(inputfile,g);
	XuatMaTranKe(g);
	if(ktDuongCheo(g)==0&&ktVoHuong(g)==0) printf("do thi hop le\n");
	else printf("do thi khong hop le\n");
	
	if(ktVoHuong(g)==-1) printf("do thi co huong\n"); else printf("do thi vo huong\n");
	SoBacCuaMT(g);
	return 0;
}
