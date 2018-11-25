#include<stdio.h>
#include<string.h>

void main()
{
    int arr[11],f,l,i,ele,temp,choice;
    f=0;
    l=0;

    do
    {
        printf("\nMENU\n1.Insertion\n2.Deletion\n3.Dispaly\n4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: if(l==0)
                    {
                        printf("Enter element: ");
                        scanf("%d",&ele);
                        f=1;
                        l=1;
                        arr[l]=ele;

                    }
                    else if(f==(l+1))
                    {
                        printf("\nQueue is FULL\n");
                    }
                    else
                    {
                        temp=l;
                        temp=((temp%10)+1);
                        if(temp!=f)
                        {
                            l=temp;
                            printf("Enter element: ");
                            scanf("%d",&ele);
                            arr[l]=ele;
                        }
                        else
                        {
                            printf("\nQueue is FULL\n");
                        }
                    }
                    break;
            case 2: if(f==0)
                    {
                        printf("\nQueue is EMPTY\n");
                    }
                    else
                    {
                        if(f==l)
                        {
                            f=0;
                            l=0;
                        }
                        else
                        {
                            f=((f%10)+1);

                        }
                    }
                    break;
            case 3: i=f;
                    while(i!=(l+1))
                    {
                        if(l==10 && i==10)
                        {
                            printf(" %d <-",arr[i]);
                            break;
                        }
                        printf(" %d <-",arr[i]);
                        i=((i%10)+1);
                    }
                    break;
        }
        
    }while(choice==1 || choice==2 || choice==3);
}
