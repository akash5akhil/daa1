#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int count=0;
int x[20]={0};
void disp(int n);

int place(int k,int i)
{
	int j;
	for(j=1;j<=k-1;j++)
	{
		if((x[j]==i) || abs(x[j]-i)==abs(j-k))
		return 0;
	}
	return 1;
}

void nqueens(int k, int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			x[k]=i;
			if(k==n)
			{
				printf("\n");
				disp(n);
				printf("\n\n");
			}
			else
				nqueens(k+1,n);
		}
	}
}

void disp(int n)						//preincrement
{
 	int i,j;
	 printf("\n\nSolution %d:\n\n",++count);
 	
 	for(i=1;i<=n;++i)
  		printf("\t%d",i);
 
 	for(i=1;i<=n;++i)
 	{
  		printf("\n\n%d",i);
  		for(j=1;j<=n;++j) 
  		{
   			if(x[i]==j)
    				printf("\tQ"); 
   			else
   	 			printf("\t-"); 
  		}
 	}
}
 

void main()
{
	int n;
	printf("\n Enter the no. of queens");
	scanf("%d",&n);
	nqueens(1,n);
}

/*
OUTPUT:
info-61@pccoe:~/TEIT132$ gcc 2assignment5.c
info-61@pccoe:~/TEIT132$ ./a.out

 Enter the no. of queens5



Solution 1:

	1	2	3	4	5

1	Q	-	-	-	-

2	-	-	Q	-	-

3	-	-	-	-	Q

4	-	Q	-	-	-

5	-	-	-	Q	-




Solution 2:

	1	2	3	4	5

1	Q	-	-	-	-

2	-	-	-	Q	-

3	-	Q	-	-	-

4	-	-	-	-	Q

5	-	-	Q	-	-




Solution 3:

	1	2	3	4	5

1	-	Q	-	-	-

2	-	-	-	Q	-

3	Q	-	-	-	-

4	-	-	Q	-	-

5	-	-	-	-	Q




Solution 4:

	1	2	3	4	5

1	-	Q	-	-	-

2	-	-	-	-	Q

3	-	-	Q	-	-

4	Q	-	-	-	-

5	-	-	-	Q	-




Solution 5:

	1	2	3	4	5

1	-	-	Q	-	-

2	Q	-	-	-	-

3	-	-	-	Q	-

4	-	Q	-	-	-

5	-	-	-	-	Q




Solution 6:

	1	2	3	4	5

1	-	-	Q	-	-

2	-	-	-	-	Q

3	-	Q	-	-	-

4	-	-	-	Q	-

5	Q	-	-	-	-




Solution 7:

	1	2	3	4	5

1	-	-	-	Q	-

2	Q	-	-	-	-

3	-	-	Q	-	-

4	-	-	-	-	Q

5	-	Q	-	-	-




Solution 8:

	1	2	3	4	5

1	-	-	-	Q	-

2	-	Q	-	-	-

3	-	-	-	-	Q

4	-	-	Q	-	-

5	Q	-	-	-	-




Solution 9:

	1	2	3	4	5

1	-	-	-	-	Q

2	-	Q	-	-	-

3	-	-	-	Q	-

4	Q	-	-	-	-

5	-	-	Q	-	-




Solution 10:

	1	2	3	4	5

1	-	-	-	-	Q

2	-	-	Q	-	-

3	Q	-	-	-	-

4	-	-	-	Q	-

5	-	Q	-	-	-
*/
