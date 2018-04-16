#include <stdio.h>

void adjust_max(int l[10],int i,int n)
{
	int j=2*i,item=l[i];

	while(j<=n)
	{
		if((j<n) && (l[j]<l[j+1]))
			j++;
		if(item>=l[j])break;
		
		l[j/2]=l[j];
		j=j*2;
	}

	l[j/2]=item;
}

void heapsort(int l[10],int n)
{
	int i,temp;

	for(i=n/2;i>=1;i--)
		adjust_max(l,i,n);

	for(i=n;i>=2;i--)
	{
		temp=l[i];
		l[i]=l[1];
		l[1]=temp;
		adjust_max(l,1,i-1);
	}
}

void store(int l[10],int n)
{
	float mrt;
	int sum=0,i,j;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
			sum=sum+l[j];
	}

	printf("\nTotal retrival time:%d\n",sum);
	mrt=(float)sum/n;
	printf("Mean retrival time:%f\n",mrt);


}



int main()
{
	int i,l[10],n,j,sum;

	printf("Enter no of programs:");
	scanf("%d",&n);

	printf("Enter length of programs:\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&l[i]);
	}

	heapsort(l,n);

	printf("Sorted length of programs are:\n");
	for(i=1;i<=n;i++)
	{
		printf("%d ",l[i]);
	}
	printf("\n");
	store(l,n);

	
}
/*Enter no of programs:3
Enter length of programs:
5 3 10
Sorted length of programs are:
3 5 10 

Total retrival time:29
Mean retrival time:9.666667
*/
