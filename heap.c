//Surya Merin Philip
//S3D
//51
#include <stdio.h>
void main()
{
    int heap[10],n,i,j,c,root,temp;
    printf("\n Enter no of elements :");
    scanf("%d",&n);
    printf("\n Enter the nos : ");
    for (i=0; i< n;i++)
	scanf("%d",&heap[i]);
    for (i= 1;i<n;i++)
    {
	c=i;
	do
        {
	    root= (c-1)/2;             
	    if (heap[root]<heap[c])
	    {

             temp= heap[root];
	     heap[root]=heap[c];
	     heap[c]=temp;

            }
	   c=root;

        }while(c!=0);
    }
    printf("Heap array : ");
    for (i= 0;i<n;i++)
        printf("%d\n ", heap[i]);
    for (j=n-1;j>=0;j--)
    {
        temp=heap[0];
	heap[0] = heap[j];
        heap[j] = temp;
	root=0;
	do 
	{

            c = 2 * root + 1; 
            if ((heap[c]<heap[c+1]) && c<j-1)
		c++;
	    if (heap[root]<heap[c] && c<j)   
	    {
		temp=heap[root];
		heap[root]=heap[c];
		heap[c]=temp;
	     }
	    root=c;

        } while(c<j);
    } 
    printf("\n sorted array ");
    for (i = 0; i < n; i++)
	printf("\n %d", heap[i]);
}
OUTPUT
 Enter no of elements :4

 Enter the nos : 4
7
2
6
Heap array : 7
 6
 2
 4
 
 sorted array 
 2
 4
 6
 7
