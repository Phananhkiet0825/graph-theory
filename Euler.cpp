#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
#define input "test03_4.txt"

struct Dothi{
	int n;
	int g[MAX][MAX];
};
struct step{
	int n;
	int a[MAX];
};

int inputfile (char name[MAX], Dothi&a)
{
	FILE*f;
	f=fopen(name,"rt");
	if(f==NULL) 
	{
		printf("\n doc file that bai\n");
		return 0;
	}
	printf("\n doc file thanh cong\n");
	fscanf(f,"%d",&a.n);
	for(int i =0 ;i<a.n;i++)
		for(int j=0; j<a.n;j++)
			fscanf(f,"%d",&a.g[i][j]);
	fclose(f);
	return 1;
}
void output (Dothi a)
{
	for(int i =0 ;i<a.n;i++)
	{
		printf("\n");
		for(int j=0; j<a.n;j++)
		{
			printf("%3d",a.g[i][j]);
		}
	}
}
void popin (step & way, int k)
{
	way.a[way.n]=k;
	way.n++;
}
void popout (step & way)
{	
	way.n--;
}

int ktNULL (Dothi a)
{
	for(int i =0 ;i<a.n;i++)
	{
		for(int j=0; j<a.n;j++)
		{
			if(a.g[i][j]!=0) return 0;
		}
	}
	return 1;
}
void outputArray( int a[],int n)
{
	printf("\n");
	for(int i =0 ;i<n;i++)
	{
		printf("%3d",a[i]);
	}
}

void EulerCycle ( Dothi &a,int star,step &way)
{
	for(int i =0 ; i<a.n;i++)
	{
		if(a.g[star][i]!=0) 
		{
			a.g[i][star]=0;
			a.g[star][i]=0;
			EulerCycle(a,i,way);
		}
		
	}
	popin(way,star);
}
int Rank(Dothi a, int dinh)
{
	int tong =0;
	for(int i=0;i<a.n;i++)
		if(a.g[dinh][i]!=0) tong+=a.g[dinh][i];
	return tong;		
}
int ktloai( Dothi a)
{
	int count =0;
	for(int i=0;i<a.n;i++)
		if(Rank(a,i)%2!=0) count ++;
	if (count ==2) return 1;
	if( count == 0) return 2;
	return 0;	
}
int timEuler (Dothi a)
{	
	Dothi b=a;
	step test;
	int kt = ktloai(a);
	if(kt == 2)
	{
		printf("\n\ndo thi Euler\n");
			EulerCycle(b,0,test);
			for(int i =0 ;i<test.n;i++)
	{
		printf("%3d",test.a[i]);
	}
	}
	if(kt==1)
	{
		printf("\n\ndo thi 1/2 Euler\n");
		for(int i =0;Rank(a,i)%2==0;i++)
			EulerCycle(b,Rank(a,i),test);
			for(int i =0 ;i<test.n-1;i++)
	{
		printf("%3d",test.a[i]);
	}
	}
	
	return 1;
	if(kt==0)
	{
	printf("\n\nko phai do thi Euler\n");
	return 0;
	}
}
int main()
{
	Dothi a;
	inputfile(input,a);
	output(a);
	step k;
	timEuler(a);
}
