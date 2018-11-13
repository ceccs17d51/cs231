include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink,*rlink;
};

void main()
{
    int key,x,cho,flag;
    struct node *head,*temp,*ptr,*ptr1,*ptr2;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->llink=head;
    head->rlink=head;

    do
    {
        ptr=head;
        printf("\nMENU\n1.Insertion (end)\n2.Insertion (in b/w)\n3.Insertion (begining)\n4.Deletion\n5.Search\n6.Display\n7.Exit\nEnter choice:");
        scanf("%d",&cho);
        if(cho==1)
        {
            while(ptr->rlink!=head)
            {
                ptr=ptr->rlink;
            }
            temp=(struct node*)malloc(sizeof(struct node));
            ptr->rlink=temp;
            printf("Enter data: ");
            scanf("%d",&x);
            temp->data=x;
            temp->rlink=head;
            temp->llink=ptr;
            head->llink=temp;
        }
        else if(cho==2)
        {
            printf("Enter key: ");
            scanf("%d",&key);
            ptr=ptr->rlink;
            while(ptr!=head)
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

        else if(cho==3)
        {
            printf("Enter key: ");
            scanf("%d",&key);
            if(ptr->rlink==head)
            {
                temp=(struct node*)malloc(sizeof(struct node));
                ptr->rlink=temp;
                temp->llink=ptr;
                temp->rlink=head;
                temp->data=key;
                head->llink=temp;
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
        else if(cho==4)
        {
            if(ptr->rlink==head)
            {
                printf("List is empty!!!");
            }
            else
            {
                printf("Enter key: ");
                scanf("%d",&key);
                flag=0;
                while(ptr->rlink!=head)
                {
                    ptr1=ptr;
                    ptr=ptr->rlink;
                    ptr2=ptr->rlink;
                    if(ptr->data==key)
                    {
                        if(ptr->rlink==head)
                        {
                            ptr1=ptr->llink;
                            ptr1->rlink=head;
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
        else if(cho==5)
        {
            if(ptr->rlink==head)
            {
                printf("Empty list!!!");
            }
            else
            {
                ptr=ptr->rlink;
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
                    ptr=ptr->rlink;
                }
                if(flag==0)
                {
                    printf("\nElement not found...");
                }
            }
        }
        else if(cho==6)
        {
            ptr=ptr->rlink;
            while(ptr!=head)
            {
                printf("%d -> ",ptr->data);
                ptr=ptr->rlink;
            }
            temp=ptr->rlink;
            printf("%d",temp->data);
        }
    }while(cho==1 || cho==2 || cho==3 || cho==4 || cho==5 || cho==6);
}
