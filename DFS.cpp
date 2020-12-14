#include<stdio.h>
#include<conio.h>
#define max 100
#define input "test5_01.txt"

struct matran {
	int size;
	int a[max][max];
};
struct stack{
	int size ;
	int s[max];
};

int LuuVet[max];
int ChuaXet[max];

int inputmt ( char name[max], matran &g)
{
	FILE*f;
	f=fopen(name,"rt");
	if(f== NULL){
		printf("doc file that bai \n");
		return 0;
	}
		printf("doc file thanh cong \n");
		fscanf(f,"%d",&g.size);
		for(int i=0;i<g.size;i++)
			for(int j=0;j<g.size;j++)
				fscanf(f,"%d",&g.a[i][j]);
	fclose(f);
	return 1;
}
void output(matran g)
{
	for(int i=0;i<g.size;i++)
		{
			printf("\n");
			for(int j=0;j<g.size;j++)
				{
				printf("%2d",g.a[i][j]);
				}
		}
}

void DFS(int v,matran g)
{	
	
	ChuaXet[v]=1;
	int u ;
	for(u=0;u<g.size;u++)
	{
		if(g.a[v][u]!=0 && ChuaXet[u]==0)
		{
			
			LuuVet[u]=v;
			DFS(u,g);
			
		}
	}
}
void thutuDFS(int v,matran g)
{	
	printf("%5d",v);
	ChuaXet[v]=1;
	int u ;
	for(u=0;u<g.size;u++)
	{
		if(g.a[v][u]!=0 && ChuaXet[u]==0)
		{
			
			LuuVet[u]=v;
			thutuDFS(u,g);
			
		}
	}
}
void duyetDFS (int star, int end, matran g)
{
	
	int i;
	for(int k=0;k<g.size;k++)
	{
	ChuaXet[k]=0;
	LuuVet[k]=-1;
	}
	DFS(star,g);
	if(	ChuaXet[end]==1)
	{
		printf("Duong di tu dinh %d --> %d \n",star,end);
		i=end;
		printf("%d",end);
		
		while(i!= star)
		{
		printf("%d",LuuVet[i]);
		i=LuuVet[i];
		}
	}
	else printf("khong tim the duong di\n");
	
	
}

void duyetthutuDFS (int star, matran g)
{
	
	int i;
	for(int k=0;k<g.size;k++)
	{
	ChuaXet[k]=0;
	LuuVet[k]=-1;
	}
	thutuDFS(star,g);
}
int main(){
	matran g;
	inputmt(input,g);
	output(g);
	
	
	// tim duong di DFS
	int s; int e;
	printf("\nMoi nhap 2 dinh \n");
	scanf("%d%d",&s,&e);
	duyetDFS(s,e,g);
	// thu tu cac dinh duoc duyet DFS
	printf("\nMoi nhap dinh S \n");
	scanf("%d",&s);
	duyetthutuDFS(s,g);
}
