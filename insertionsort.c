#include<stdio.h>
int main()
{
	int array[100],n,temp,i,j;
	printf("Enter number of elements");
	scanf("%d",&n);
	printf("Enter elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	for(i=1;i<n;i++)
	{
		temp =array[i];
		j=i-1;
		while(temp<array[j] && j>=0)
		{
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=temp;
	}
	printf("sorted order: ");
	for(i=0; i<n; i++)
		printf("%d ",array[i]);
        return 0;
}
 OUTPUT
 Enter number of elements5
Enter elements: 4
3
2
9
6
sorted order: 2 3 4 6 9
