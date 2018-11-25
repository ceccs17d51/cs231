#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};

void main()
{
    struct node *head,*temp,*tem;
    int choice,ele;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->llink=NULL;
    head->rlink=NULL;
    temp=head;

    do
    {
        printf("\n\nMENU\n1.Insertion(front)\n2.Insertion(end)\n3.Deletion(front)\n4.Deletion(end)\n5.Display\n6.Exit\nEnter choice: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            if(head->rlink==NULL)
            {
                temp=(struct node*)malloc(sizeof(struct node));
                printf("Enter element: ");
                scanf("%d",&ele);
                temp->data=ele;
                temp->llink=head;
                temp->rlink=NULL;
                head->rlink=temp;

            }
            else
            {
                temp=(struct node*)malloc(sizeof(struct node));
                printf("Enter element: ");
                scanf("%d",&ele);
                temp->data=ele;
                temp->rlink=head->rlink;
                temp->llink=head;
                head->rlink=temp;
                (temp->rlink)->llink=temp;
            }
        

        }
        else if(choice==2)
        {
            temp=head;
            while(temp->rlink!=NULL)
            {
                temp=temp->rlink;
            }
            tem=(struct node*)malloc(sizeof(struct node));
            printf("Enter element: ");
            scanf("%d",&ele);
            tem->data=ele;
            tem->rlink=NULL;
            tem->llink=temp;
            temp->rlink=tem;
        }
        else if(choice==3)
        {
            if(head->rlink==NULL)
            {
                printf("queue is EMPTY");
            }
            else
            {
                temp=head->rlink;
                head->rlink=temp->rlink;
                free(temp);
            }
            
        }
        else if(choice==4)
        {
            if(head->rlink==NULL)
            {
                printf("queue is EMPTY");
            }
            else
            {
                temp=head;
                while(temp->rlink!=NULL)
                {
                    tem=temp;
                    temp=temp->rlink;
                }
                tem->rlink=NULL;
                free(temp);

            }
        }
        else if(choice==5)
        {
            temp=head->rlink;
            while(temp!=NULL)
            {
                printf("%d <->",temp->data);
                temp=temp->rlink;
            }
            printf("NULL");
        }
    }while(choice==1 || choice==2 || choice==3 || choice==4 || choice==5);

}
