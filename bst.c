#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}*header,*new;

void getnode()
    {
        int element;
        printf("\nEnter data: ");
        scanf("%d",&element);
        new=(struct node*)malloc(sizeof(struct node));
        new->data=element;
        new->lchild=NULL;
        new->rchild=NULL;
    }

void insertion()
{
    struct node *ptr,*ptr1;
    if(header->rchild==NULL)
    {
        getnode();
        header->rchild=new;
    }
    else
    {
        int flag=0;
        getnode();
        ptr=header->rchild;
        while(ptr!=NULL)
        {
            if(new->data<ptr->data)
            {
                ptr1=ptr;
                ptr=ptr->lchild;
            }
            else if(new->data>ptr->data)
            {
                ptr1=ptr;
                ptr=ptr->rchild;
            }
            else
            {
                printf("Data already exists!! (NODE dumped)");
                free(new);
                flag=1;
                break;
            }
        }   //end of while
        if(flag==0)
        {
            if(new->data>ptr1->data)
            {
                ptr1->rchild=new;
            }
            else                              //else if(new->data<ptr1->data)
            {
                ptr1->lchild=new;
            }
        }
    }    
}

void printnode(struct node *ptr)            //recursive function to display tree in postfix form
{
    if(ptr->lchild!=NULL)
    {
        printnode(ptr->lchild);
    }
    if(ptr->rchild!=NULL)
    {
        printnode(ptr->rchild);
    }
    printf("%d ",ptr->data);
}


void display()
{
    if(header->rchild==NULL)
    {
        printf("\nTREE is EMPTY\n");
    }
    else
    {
        printf("\nTREE(in postfix form)\n");
        printnode(header->rchild);            //displays tree in postfix form
    }
}

void deletenode(struct node *ptr,struct node *ptr1)
{
    struct node *temp,*temp1;
    if(ptr->lchild==NULL && ptr->rchild==NULL)
    {
        if(ptr1->lchild==ptr)
        {
            ptr1->lchild=NULL;
            free(ptr);
        }
        else
        {
            ptr1->rchild=NULL;
            free(ptr);
        }
    }
    else if(ptr->lchild==NULL)
    {
        if(ptr1->lchild==ptr)
        {
            ptr1->lchild=ptr->rchild;
            free(ptr);
        }
        else
        {
            ptr1->rchild=ptr->rchild;
            free(ptr);
        }
    }
    else if(ptr->rchild==NULL)
    {
        if(ptr1->lchild==ptr)
        {
            ptr1->lchild=ptr->lchild;
            free(ptr);
        }
        else
        {
            ptr1->rchild=ptr->lchild;
            free(ptr);
        }
    }
    else
    {
        temp1=ptr;
        temp=ptr->rchild;
        while(temp->lchild!=NULL)
        {
            temp1=temp;
            temp=temp->lchild;
        }
        if(ptr1->lchild==ptr)
        {
            if(temp1==ptr)
            {
                ptr1->lchild=temp;
                temp->lchild=ptr->lchild;
                free(ptr);
            }
            else
            {
                temp1->lchild=temp->rchild;
                ptr1->lchild=temp;
                temp->lchild=ptr->lchild;
                temp->rchild=ptr->rchild;
                free(ptr);
            }
        }
        else                 //else if(ptr1->rchild==ptr)
        {
            if(temp1==ptr)
            {
                ptr1->rchild=temp;
                temp->lchild=ptr->lchild;
                free(ptr);
            }
            else
            {
                temp1->lchild=temp->rchild;
                ptr1->rchild=temp;
                temp->lchild=ptr->lchild;
                temp->rchild=ptr->rchild;
                free(ptr);
            }            
        }
    }
}

void deletion()
{
    int d,flag=0;
    struct node *ptr,*ptr1;
    if(header->rchild==NULL)
    {
        printf("\nTREE is EMPTY\n");
    }
    else
    {
        printf("Enter Data: ");
        scanf("%d",&d);
        ptr1=header;
        ptr=header->rchild;
        while(ptr!=NULL)
        {
            if(d<ptr->data)
            {
                ptr1=ptr;
                ptr=ptr->lchild;
            }
            else if(d>ptr->data)
            {
                ptr1=ptr;
                ptr=ptr->rchild;
            }
            else                      //else if(d==ptr->data)
            {
                deletenode(ptr,ptr1);
                ptr=NULL;
                flag=1;
                break;
            }  
        }//end of while
        if(flag==0)
        {
            printf("\nElement not Found\n");
        }
    }

}



void main()
{
    int cho;
    header=(struct node*)malloc(sizeof(struct node));
    header->data=0;
    header->lchild=NULL;
    header->rchild=NULL;
    do
    {
        printf("\nMENU\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter Choice: ");
        scanf("%d",&cho);
        switch(cho)
        {
            case 1: insertion();
                break;
            case 2: deletion();
                    break;
            case 3: display();
                    break;
        }
    }while(cho==1||cho==2||cho==3);
}
