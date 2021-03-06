/*Write a program to solve the travelling salesman problem and to print the path and the cost using
Dynamic Programming.*/

#include<stdio.h>
#include<stdlib.h>

void get();
void mincost(int city);
int least(int c);
void put();

int a[10][10],visited[10],n,cost=0;

void get()
{
	int i,j;
	printf("\n\nEnter Number of Cities: ");
	scanf("%d",&n);
	printf("\nEnter Cost Matrix: \n");
	for( i=0;i<n;i++)
     	{
     		printf("\n Enter Elements of Row # : %d\n",i+1);
     		for( j=0;j<n;j++)
     			scanf("%d",&a[i][j]);
     		visited[i]=0;
     	}
	printf("\n\nThe Cost Matrix is:\n");
	for(i=0;i<n;i++)
     	{
     		printf("\n\n");
     		for(j=0;j<n;j++)
          		printf("\t%d",a[i][j]);
        }        	
}
 
void mincost(int city)
{
	int i,ncity;
	visited[city]=1;
	printf("%d ===> ",city+1);
	ncity=least(city);

	if(ncity==999)
    	{
    		ncity=0;
     		printf("%d",ncity+1);
     		cost+=a[city][ncity];
     		return;
     	}
	mincost(ncity);
}

int least(int c)
{
	int i,nc=999;
	int min=999,kmin;

	for(i=0;i<n;i++)
    	{
     		if((a[c][i]!=0)&&(visited[i]==0))
     			if(a[c][i]<min)
     			{
      				min=a[i][0]+a[c][i];
      				kmin=a[c][i];
      				nc=i;
      			}
     	}
	if(min!=999)
		cost+=kmin;
	return nc;
}
 
void put()
{
	printf("\n\nMinimum cost:");
	printf("%d",cost);
}
 
int main()
{
	get();
	printf("\n\nThe Path is:\n\n");
	mincost(0);
	put();
}
/*OUTPUT:
info-61@pccoe:~/Desktop$ gcc tsp.c
info-61@pccoe:~/Desktop$ ./A.OUT
bash: ./A.OUT: No such file or directory
info-61@pccoe:~/Desktop$ ./a.out


Enter Number of Cities: 4

Enter Cost Matrix: 

 Enter Elements of Row # : 1
0
10
15
20

 Enter Elements of Row # : 2
5
0
9
10

 Enter Elements of Row # : 3
6
13
0
12

 Enter Elements of Row # : 4
8
8
9
0


The Cost Matrix is:


	0	10	15	20

	5	0	9	10

	6	13	0	12

	8	8	9	0

The Path is:

1 ===> 2 ===> 4 ===> 3 ===> 1

Minimum cost:35info-61@pccoe:~/Desktop$ 
*/


