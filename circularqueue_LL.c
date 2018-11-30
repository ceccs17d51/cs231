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
    int ele,choice;

    head=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->link=NULL;

    do
    {
        printf("\n\nMENU\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter Choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            if(head->link==NULL)
            {
                temp=(struct node*)malloc(sizeof(struct node));
                printf("Enter element: ");
                scanf("%d",&ele);
                temp->data=ele;
                head->link=temp;
                temp->link=head->link;
                
            }
            else
            {
                tem=head->link;
                temp=(struct node*)malloc(sizeof(struct node));
                printf("Enter element: ");
                scanf("%d",&ele);
                temp->data=ele;
                while(tem->link!=head->link)
                {
                    tem=tem->link;
                }
                temp->link=tem->link;
                tem->link=temp;
            }
        }
        else if(choice==2)
        {
            if(head->link==NULL)
            {
                printf("Queue is Empty");
            }
            else
            {
                if(temp==temp->link)
                {
                    head->link=NULL;
                    free(temp);
                }
                else
                {
                    temp=head->link;
                    head->link=(head->link)->link;
                    tem=head->link;
                    while(tem->link!=temp)
                    {
                        tem=tem->link;
                    }
                    tem->link=head->link;
                    free(temp);
                }
            }
        }
        else if(choice==3)
        {
            if(head->link==NULL)
            {
                printf("queue is empty");
            }
            else
            {
                temp=head->link;
                printf("%d <-",temp->data);
                temp=temp->link;
                while(temp!=head->link)
                {
                    printf("%d <-",temp->data);
                    temp=temp->link;
                }
                printf("%d",temp->data);

            }

        }
    }while(choice==1 || choice==2 || choice==3);
}
