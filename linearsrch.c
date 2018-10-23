#include<stdio.h>
int main()
{
	int a[100],i,n,key;
	printf("Enter no of numbers:");
	scanf("%d",&n);
	printf("enter the elements");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the number to be searched:");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			printf("key is found at %d\n",i+1);
			break;
		}
	}
	if(i==n)
	{
		printf(" Not found\n");
	}
	return 0;
}
















