//Surya Merin Philip
//S3D
//51
#include<stdio.h>
int main()
{
	int array[100],i,n,j,temp;
	printf("enter the number of elements:");
	scanf("%d",&n);
	printf("enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&array[i]);
	for(j=0;j<n-1;j++)
	for(i=0;i<n-j-1;i++)
	{
		if(array[i]>array[i+1])
		{
			temp=array[i];		
			array[i]=array[i+1];
			array[i+1]=temp;
		}
	}
	printf("sorted order:");
	for(i=0;i<n;i++)
		printf("%d ",array[i]);
	return 0;
}
OUTPUT
enter the number of elements:5
enter the elements:3
2
7
5
1
sorted order:1 2 3 5 7 
