#include<stdio.h>
#include<conio.h>
#define max 100
#define input "test_7.txt"
struct matran{
	int size;
	int g[max][max];
};
int InPutMT(char name[100],matran & a){
	FILE*f;
	f=fopen(name,"rt");
	if(f==NULL)
	{
	printf("\nERROR\n");
	return 0;
	}
	fscanf(f,"%d",&a.size);
	for (int i=0;i<a.size;i++) 
		for (int j=0;j<a.size;j++)  
			fscanf(f,"%d",&a.g[i][j]);
	printf("\nInput success\n");
	fclose(f);
	return 1;	
}
int xetlienthong(matran a)
{
	int sotplienthong=0;
	int nhan[a.size];
	
	for(int i=0;i<a.size;i++)
	{
		nhan[i]=0;
	}
	
	for(int i=0;i<a.size;i++)
	{
	if(nhan[i]==0)
		{
			int star =i;
			nhan[star]=sotplienthong;
			
			for(;star<a.size;star++)
				
				for(int j =0 ; j<a.size;j++)
				
					if(a.g[star][j]!=0&&nhan[j]==0)
					{		
						nhan[j]=nhan[star];		
					}
			sotplienthong++;	
		}
	}	
	
	for(int rank=1 ; rank<sotplienthong;rank++)
		{
		printf("\nPhan tu lien thong thu %d",rank);
			for(int i=0;i<a.size;i++)
				if(nhan[i]==rank)printf("%3d",i);
		}
	return sotplienthong;		
}

void output (matran a )
{
	int n = a.size;
	for (int i =0 ; i<n; i ++)
	{
		printf("\n");
		for (int j =0 ; j<n; j ++)
		printf("%d",a.g[i][j]);
	}
}
int main()
{
	matran a;
	InPutMT(input,a);
	
	xetlienthong(a);
	
}
