#include<stdio.h>
#include<conio.h>
#define max 100
#define input "test5_01.txt"

struct matran {
	int size;
	int a[max][max];
};
struct queue{
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
void KhoiTao(queue &q)
{
	q.size =0;
}
void inputqueue(queue &q, int n)
{
	q.s[q.size]=n;
	q.size++;
}
void outputqueue(queue &q, int &n)
{
	n=q.s[0];
	for(int i=0;i<q.size-1;i++)
		q.s[i]=q.s[i+1];
	q.size--;	
}
int ktNULL(queue q)
{
	if(q.size<=0) return 1;
	return 0;
}
void BFS(int v,matran g)
{	
	queue q;	
	KhoiTao(q);
	inputqueue(q,v);
	while(!ktNULL(q))
	{		
		outputqueue(q,v);
		ChuaXet[v]=1;
		
		for(int u =0; u <g.size;u++)
		{
			
			if(g.a[v][u]!=0 && ChuaXet[u]==0)
			{			
			
			inputqueue(q,u);
				
			if(LuuVet[u]==-1)
			LuuVet[u]=v;	
		 	}
		}
	}
}
int find (queue k, int n)
{
	for(int i=0; i <k.size;i++)
		if(k.s[i]==n) return 1;
		return 0;
}
void ThuTuBFS(int v,matran g)
{	
	queue thutu;
	queue q;	
	KhoiTao(q);
	KhoiTao(thutu);
	inputqueue(q,v);
	while(!ktNULL(q))
	{	
		if(find(thutu,v)==0)inputqueue(thutu,v);
		outputqueue(q,v);
		ChuaXet[v]=1;
		for(int u =0; u <g.size;u++)
		{	
			if(g.a[v][u]!=0 && ChuaXet[u]==0)
			{			
			inputqueue(q,u);
			if(LuuVet[u]==-1)
			LuuVet[u]=v;	
		 	}
		}
	}
	for(int i=0;i<thutu.size;i++)
	printf("%5d",thutu.s[i]);
}
void duyetBFS (int &star, int end, matran g)
{
	
	int i;
	for(int k=0;k<g.size;k++)
	{
	ChuaXet[k]=0;
	LuuVet[k]=-1;
	}
	BFS(star,g);
	if(	ChuaXet[end]==1)
	{
		printf("Duong di tu dinh %d --> %d \n",star,end);
		i=end;
		printf("%d",end);
		
		while(i!= star)
		{
		printf("-->");
		printf("%d",LuuVet[i]);
		
		i=LuuVet[i];
		}
	}
	else printf("khong tim the duong di\n");

}
void duyetthutuBFS (int &star, matran g)
{
	
	int i;
	for(int k=0;k<g.size;k++)
	{
	ChuaXet[k]=0;
	LuuVet[k]=-1;
	}
	printf("\n thu tu duyet theo BFS la \n");
	ThuTuBFS(star,g);
	
}




int main(){
	matran g;
	inputmt(input,g);
	output(g);
	
	
	// tim duong di BFS
	int s; int e;
	printf("\nMoi nhap 2 dinh \n");
	scanf("%d%d",&s,&e);
	duyetBFS(s,e,g);
	// thu tu cac dinh duoc duyet BFS
	duyetthutuBFS(s,g);
}
