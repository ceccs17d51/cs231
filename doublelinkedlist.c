//Surya Merin Philip
//S3D
//51
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink,*rlink;
};

void main()
{
    int key,x,choice,flag;
    struct node *head,*temp,*ptr,*ptr1,*ptr2;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->llink=NULL;
    head->rlink=NULL;

    do
    {
        ptr=head;
        printf("\nMENU\n1.Insertion at end\n2.Insertion in between\n3.Insertion at front\n4.Deletion\n5.Search\n6.Display\n7.Exit\nEnter choice:");
        scanf("%d",&choice);
        if(choice==1)
        {
            while(ptr->rlink!=NULL)
            {
                ptr=ptr->rlink;
            }
            temp=(struct node*)malloc(sizeof(struct node));
            ptr->rlink=temp;
            printf("Enter data: ");
            scanf("%d",&x);
            temp->data=x;
            temp->rlink=NULL;
            temp->llink=ptr;
        }
        else if(choice==2)
        {
            printf("Enter key: ");
            scanf("%d",&key);
            ptr=ptr->rlink;
            while(ptr!=NULL)
            {
                if(ptr->data==key)
                {
                    temp=(struct node*)malloc(sizeof(struct node));
                    ptr1=ptr->rlink;
                    ptr->rlink=temp;
                    temp->llink=ptr;
                    ptr1->llink=temp;
                    temp->rlink=ptr1;
                    printf("Enter data: ");
                    scanf("%d",&x);
                    temp->data=x;

                }
                ptr=ptr->rlink;
            }
        }

        else if(choice==3)
        {
            printf("Enter key: ");
            scanf("%d",&key);
            if(ptr->rlink==NULL)
            {
                temp=(struct node*)malloc(sizeof(struct node));
                ptr->rlink=temp;
                temp->llink=ptr;
                temp->rlink=NULL;
                temp->data=key;
            }
            else 
            {
                temp=(struct node*)malloc(sizeof(struct node));
                ptr1=ptr->rlink;
                ptr->rlink=temp;
                temp->llink=ptr;
                temp->rlink=ptr1;
                ptr1->llink=temp;
                temp->data=key;
            }
        }
        else if(choice==4)
        {
            if(ptr->rlink==NULL)
            {
                printf("List is empty!!!");
            }
            else
            {
                printf("Enter key: ");
                scanf("%d",&key);
                flag=0;
                while(ptr->rlink!=NULL)
                {
                    ptr1=ptr;
                    ptr=ptr->rlink;
                    ptr2=ptr->rlink;
                    if(ptr->data==key)
                    {
                        if(ptr->rlink==NULL)
                        {
                            ptr1=ptr->llink;
                            ptr1->rlink=NULL;
                            free(ptr);
                            flag+=1;    

                        }
                        else
                        {
                            ptr1=ptr->llink;
                            ptr2=ptr->rlink;
                            ptr1->rlink=ptr2;
                            ptr2->llink=ptr1;
                            free(ptr);
                            flag+=1;
                        }
                    }
                }
                if(flag==0)
                {
                    printf("Key not found!!!");
                }
            }
        }
        else if(choice==5)
        {
            if(ptr->rlink==NULL)
            {
                printf("Empty list!!!");
            }
            else
            {
                ptr=ptr->rlink;
                flag=0;
                printf("Enter key: ");
                scanf("%d",&key);
                while(ptr!=NULL)
                {
                    if(ptr->data==key)
                    {
                        printf("\nElement found...");
                        flag+=1;
                    }
                    ptr=ptr->rlink;
                }
                if(flag==0)
                {
                    printf("\nElement not found...");
                }
            }
        }
        else if(choice==6)
        {
            ptr=ptr->rlink;
            while(ptr!=NULL)
            {
                printf("%d -> ",ptr->data);
                ptr=ptr->rlink;
            }
            printf("NULL");
        }
}while(choice==1 || choice==2 || choice==3 || choice==4 || choice==5 || choice==6);
}
output

MENU
1.Insertion
2.Deletion
3.Display
Enter choice: 2

Queue is EMPTY

MENU
1.Insertion
2.Deletion
3.Display
Enter choice: 1
Enter element: 3

MENU
1.Insertion
2.Deletion
3.Display
Enter choice: 1
Enter element: 8

MENU
1.Insertion
2.Deletion
3.Display
Enter choice: 3
3 <-8 <- NULL
MENU
1.Insertion
2.Deletion
3.Display
Enter choice: 2

DELETED 3 
MENU
1.Insertion
2.Deletion
3.Display
Enter choice: 1
Enter element: 9

MENU
1.Insertion
2.Deletion
3.Display
Enter choice: 3
8 <-9 <- NULL
MENU
1.Insertion
2.Deletion
3.Display
Enter choice: 8
