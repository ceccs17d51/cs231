//Surya Merin Philip
//S3D
//51
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lchild,*rchild;
}*header,*new,*ser_node,*temp;

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
void search(struct node *ptr,int ele)
{
    if(ptr->lchild!=NULL)
        search(ptr->lchild,ele);
    if(ptr->rchild!=NULL)
        search(ptr->rchild,ele);
    if(ptr->data==ele)
        ser_node=ptr;
    if(ptr->rchild!=NULL && (ptr->rchild)->data==ele || ptr->lchild!=NULL && (ptr->lchild)->data==ele)
        temp=ptr;
//    if(ptr->rchild==ser_node || ptr->lchild==ser_node)
//        temp=ptr;
}    
void insertion()
{
    int ele,cho;
    if(header->rchild==NULL)
    {
        getnode();
        header->rchild=new;
    }
    else
    {
        ser_node=NULL;
        getnode();
        printf("Select node (by data): ");
        scanf("%d",&ele);
        search(header->rchild,ele);
        if(ser_node==NULL)
        {
            printf("\nNode not exist\n");
        }
        else
        {
            printf("\nSelect child node\n1.left\n2.Right\nEnter Choice: ");
            scanf("%d",&cho);
            if(ser_node->lchild==NULL && cho==1)
                ser_node->lchild=new;
            else if(ser_node->rchild==NULL && cho==2)
                ser_node->rchild=new;
            else
            {
                printf("\nNode already occupied\n");
                free(new);
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

void finddeep()
{
    struct node *ptr,*ptr1,*tem,*tem1;
    ptr1=temp;
    ptr=ser_node;
    tem1=ptr;
    tem=ptr->rchild;
    while(tem->lchild!=NULL)
    {
        tem1=tem;
        tem=tem->lchild;
    }
    if(ptr1->lchild==ptr)
    {
        if(tem1==ptr)
        {
            ptr1->lchild=tem;
            tem->lchild=ptr->lchild;
            free(ptr);
        }
        else
        {
            tem1->lchild=tem->rchild;
            ptr1->lchild=tem;
            tem->lchild=ptr->lchild;
            tem->rchild=ptr->rchild;
            free(ptr);
        }
    }
    else                 //else if(ptr1->rchild==ptr)
    {
        if(tem1==ptr)
        {
            ptr1->rchild=tem;
            tem->lchild=ptr->lchild;
            free(ptr);
        }
        else
        {
            tem1->lchild=tem->rchild;
            ptr1->rchild=tem;
            tem->lchild=ptr->lchild;
            tem->rchild=ptr->rchild;
            free(ptr);
        }            
    }
}

void deletion()
{
    int ele;
    if(header->rchild==NULL)
        printf("\nTree is Empty\n");
    else
    {
        ser_node=NULL;
        printf("Select node (by data): ");
        scanf("%d",&ele);
        search(header->rchild,ele);
        printf("CHECK");
        if(ser_node==header->rchild)
            temp=header;
        if(ser_node==NULL)
        {
            printf("\nNode not exist\n");
        }
        else
        {
            if(ser_node->lchild==NULL && ser_node->rchild==NULL)
            {
                if(temp->lchild==ser_node)
                    temp->lchild=NULL;
                else
                    temp->rchild=NULL;
                free(ser_node);
            }
            else if(ser_node->lchild==NULL)
            {
                if(temp->lchild==ser_node)
                    temp->lchild=ser_node->rchild;
                else
                    temp->rchild=ser_node->rchild;
                free(ser_node);                
            }
            else if(ser_node->rchild==NULL)
            {
                if(temp->lchild==ser_node)
                    temp->lchild=ser_node->lchild;
                else
                    temp->rchild=ser_node->lchild;
                free(ser_node);                
            }            
            else
            {
                finddeep();
            }
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
        printf("\n   MENU\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter Choice: ");
        scanf("%d",&cho);
        if(cho==1)
            insertion();
        else if(cho==2)
            deletion();
        else if(cho==3)
            display();
    }while(cho==1||cho==2||cho==3);
}

//****OUTPUT****

/*
   MENU
1.Insertion
2.Deletion
3.Display
4.Exit
Enter Choice: 1
Enter data: 5
   MENU
1.Insertion
2.Deletion
3.Display
4.Exit
Enter Choice: 1
Enter data: 7
Select node (by data): 5
Select child node
1.left
2.Right
Enter Choice: 2
   MENU
1.Insertion
2.Deletion
3.Display
4.Exit
Enter Choice: 1
Enter data: 6
Select node (by data): 7
Select child node
1.left
2.Right
Enter Choice: 1
   MENU
1.Insertion
2.Deletion
3.Display
4.Exit
Enter Choice: 1
Enter data: 8
Select node (by data): 7
Select child node
1.left
2.Right
Enter Choice: 2
   MENU
1.Insertion
2.Deletion
3.Display
4.Exit
Enter Choice: 3
TREE(in postfix form)
6 8 7 5
   MENU
1.Insertion
2.Deletion
3.Display
4.Exit
Enter Choice: 2
Select node (by data): 7
   MENU
1.Insertion
2.Deletion
3.Display
4.Exit
Enter Choice: 3
TREE(in postfix form)
6 8 5
   MENU
1.Insertion
2.Deletion
3.Display
4.Exit
Enter Choice:4
*/
