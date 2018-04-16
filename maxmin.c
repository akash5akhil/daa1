#include<stdio.h>
void maxmin(int a[30],int i,int j,int *max,int *min);

void main()
{
	int a[30];
	int i=0,n,min,max,j;

	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("\nEnter the elements of the array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nElements of the array:");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}

	j=n-1;
	min=max=a[0];
	maxmin(a,0,n-1,&max,&min);
	printf("\nmax=%d min=%d",max,min);
}

void maxmin(int a[30],int i,int j,int *max,int *min)
{
	if(i==j)				//small(P) n=1
		*max=*min=a[i];
	else if(i==j-1)				//small(P) n=2
	{
		if(a[i]<a[j])
		{
			*max=a[j];
			*min=a[i];
		}
		else
		{
			*max=a[i];
			*min=a[j];
		}
	}
	else 					//n>2
	{
		int mid;
		mid=(i+j)/2;
		int max1,min1;
		maxmin(a,i,mid,max,min);
		maxmin(a,mid+1,j,&max1,&min1);
		if(max1>*max)
			*max=max1;
		if(min1<*min)
			*min=min1;		
	}
}

/*OUTPUT
info-61@pccoe:~/Desktop$ gcc assignment1al.c
info-61@pccoe:~/Desktop$ ./a.out
Enter the number of elements:6

Enter the elements of the array:44
55
33
22
77
11

Elements of the array:44	55	33	22	77	11	
max=77 min=11info-61@pccoe:~/Desktop$ 
*/

