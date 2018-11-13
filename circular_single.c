#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void main()
{
    int key,x,cho,flag;
    struct node *head,*temp,*ptr,*ptr1;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->link=head;

    do
    {
        ptr=head;
        printf("\nMENU\n1.Insertion (end)\n2.Insertion (in b/w)\n3.Deletion\n4.Search\n5.Display\n6.Exit\nEnter choice:");
        scanf("%d",&cho);
        if(cho==1)
        {
            while(ptr->link!=head)
            {
                ptr=ptr->link;
            }
            temp=(struct node*)malloc(sizeof(struct node));
            ptr->link=temp;
            printf("Enter data: ");
            scanf("%d",&x);
            temp->data=x;
            temp->link=head;
        }
        else if(cho==2)
        {
            printf("Enter key: ");
            scanf("%d",&key);
            ptr=ptr->link;
            while(ptr!=head)
            {
                if(ptr->data==key)
                {
                    temp=(struct node*)malloc(sizeof(struct node));
                    ptr1=ptr->link;
                    ptr->link=temp;
                    temp->link=ptr1;
                    printf("Enter data: ");
                    scanf("%d",&x);
                    temp->data=x;

                }
                ptr=ptr->link;
            }
        }
        else if(cho==3)
        {
            if(ptr->link==NULL)
            {
                printf("List is empty!!!");
            }
            else
            {
                printf("Enter key: ");
                scanf("%d",&key);
                flag=0;
                while(ptr->link!=head)
                {
                    ptr1=ptr;
                    ptr=ptr->link;
                    if(ptr->data==key)
                    {
                        ptr1->link=ptr->link;
                        free(ptr);
                        flag+=1;
                    }
                }
                if(flag==0)
                {
                    printf("Key not found!!!");
                }
            }
        }
        else if(cho==4)
        {
            if(ptr->link==head)
            {
                printf("Empty list!!!");
            }
            ptr=ptr->link;
            flag=0;
            printf("Enter key: ");
            scanf("%d",&key);
            while(ptr!=head)
            {
                if(ptr->data==key)
                {
                    printf("\nElement found...");
                    flag+=1;
                }
                ptr=ptr->link;
            }
            if(flag==0)
            {
                printf("\nElement not found...");
            }
        }
        else if(cho==5)
        {
            ptr=ptr->link;
            while(ptr!=head)
            {
                printf("%d -> ",ptr->data);
                ptr=ptr->link;
            }
            temp=ptr->link;
            printf("%d",temp->data);
        }
    }while(cho==1 || cho==2 || cho==3 || cho==4 || cho==5);
}
