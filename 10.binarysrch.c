//Surya Merin Philip
//S3D
//51
#include<stdio.h>
int main()
{
    int a[50],i,n,key,flag=0,first,last,mid;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter array elements");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nEnter the element to search:");
    scanf("%d",&key);
    first=0;
    last=n-1;
    while(first<=last)
    {
        mid=(first+last)/2;
        if(key==a[mid])
	{
            flag=1;
            break;
        }
        else
            if(key>a[mid])
                first=mid+1;
            else
                last=mid-1;
}
	if(flag==1)
        	printf("\nElement found at position %d",mid+1);
	else
        	printf("\nElement not found");
	return 0;
}


OUTPUT
Script started on 2018-11-29 23:10:41+0530
Enter number of elements:4
Enter array elements8
6
4
2

Enter the element to search:6

Element found at position 2]0;
Script done on 2018-11-29 23:11:12+0530
