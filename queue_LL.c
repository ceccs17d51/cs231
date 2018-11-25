#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void main()
{
    struct node *head,*temp,*tem;
    int cho,ele;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=NULL;
    head->link=NULL;
    do
    {
        printf("\nMENU\n1.Insertion\n2.Deletion\n3.Display\nEnter choice: ");
        scanf("%d",&cho);

        switch(cho)
        {
            case 1: printf("Enter element: ");
                    scanf("%d",&ele);
                    tem=head;
                    while(tem->link!=NULL)
                    {
                        tem=tem->link;
                    }
                    temp=(struct node*)malloc(sizeof(struct node));
                    temp->link=NULL;
                    tem->link=temp;
                    temp->data=ele;
                    break;
            case 2: if(head->link==NULL)
                    {
                        printf("\nQueue is EMPTY\n");
                    }
                    else
                    {
                        tem=head->link;
                        temp=tem->link;
                        head->link=temp;
                        printf("\nDELETED %d ",tem->data);
                        free(tem);
                    }
                    break;
            case 3: if(head->link==NULL)
                    {
                        printf("\nQueue is EMPTY\n");
                    }
                    else
                    {
                        temp=head->link;
                        while(temp!=NULL)
                        {
                            printf("%d <-",temp->data);
                            temp=temp->link;
                        }
                        printf(" NULL");
                    }
                    break;
        }
    }while(cho==1 || cho==2 || cho==3);
}
