//Surya Merin Philip
//S3D
//51
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int exp,coeff;
    struct node *link;
};

void main()
{
    struct node *temp,*head,*head1,*head2,*ptr,*ptr1,*ptr2;
    int e,c,cho;

    head=(struct node*)malloc(sizeof(struct node));
    head->exp=0;
    head->coeff=0;
    head->link=NULL;

    head1=(struct node*)malloc(sizeof(struct node));
    head1->exp=0;
    head1->coeff=0;
    head1->link=NULL;

    head2=(struct node*)malloc(sizeof(struct node));
    head2->exp=0;
    head2->coeff=0;
    head2->link=NULL;

    ptr=head1;
    printf("First Polynomial \n");
    do
    {
        printf("Enter coefficient: ");
        scanf("%d",&c);
        printf("Enter exponent: ");
        scanf("%d",&e);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->exp=e;
        temp->coeff=c;
        temp->link=NULL;
        ptr->link=temp;
        ptr=ptr->link;
        printf("1. Add more elements\n2. Continue\nEnter choice: ");
        scanf("%d",&cho);
    }while(cho==1);

    printf("\n\nSecond polynomial \n");
    ptr=head2;
    do
    {
        printf("Enter coefficient: ");
        scanf("%d",&c);
        printf("Enter exponent: ");
        scanf("%d",&e);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->exp=e;
        temp->coeff=c;
        temp->link=NULL;
        ptr->link=temp;
        ptr=ptr->link;
        printf("1. Add more elements\n2. Continue\nEnter choice: ");
        scanf("%d",&cho);
    }while(cho==1);

    ptr=head;
    ptr1=head1->link;
    ptr2=head2->link;
    if(ptr1==NULL || ptr2==NULL)
    {
        printf("Data Insufficient!!!");
    }
    else
    {
        while(ptr1!=NULL && ptr2!=NULL)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            ptr->link=temp;
            temp->link=NULL;
            ptr=ptr->link;
            if(ptr1->exp==ptr2->exp)
            {
                ptr->exp=ptr1->exp;
                ptr->coeff=ptr1->coeff+ptr2->coeff;
                ptr1=ptr1->link;
                ptr2=ptr2->link;
            }

            else if(ptr1->exp > ptr2->exp)
            {
                ptr->exp=ptr1->exp;
                ptr->coeff=ptr1->coeff;
                ptr1=ptr1->link;
            }

            else if(ptr2->exp > ptr1->exp)
            {
                ptr->exp=ptr2->exp;
                ptr->coeff=ptr2->coeff;
                ptr2=ptr2->link;
            }
        }
        while(ptr1!=NULL)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            ptr->link=temp;
            temp->link=NULL;
            ptr=ptr->link;
            ptr->exp=ptr1->exp;
            ptr->coeff=ptr1->coeff;
            ptr1=ptr1->link;            
        }
        while(ptr2!=NULL)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            ptr->link=temp;
            temp->link=NULL;
            ptr=ptr->link;
            ptr->exp=ptr2->exp;
            ptr->coeff=ptr2->coeff;
            ptr2=ptr2->link;            
        }            
    }

    printf("\nresult = p1 + p2\n");
    ptr1=head1->link;
    printf("p1 = ");
    while(ptr1!=NULL)
    {
        printf("%d x^%d + ",ptr1->coeff,ptr1->exp);
        ptr1=ptr1->link;
    }
    printf("0\n");

    ptr1=head2->link;
    printf("p2 = ");
    while(ptr1!=NULL)
    {
        printf("%d x^%d + ",ptr1->coeff,ptr1->exp);
        ptr1=ptr1->link;
    }
    printf("0\n");

    ptr1=head->link;
    printf("result = ");
    while(ptr1!=NULL)
    {
        printf("%d x^%d + ",ptr1->coeff,ptr1->exp);
        ptr1=ptr1->link;
    }
    printf("0\n");

}
OUTPUT
First Polynomial 
Enter coefficient: 4
Enter exponent: 2
1. Add more elements
2. Continue
Enter choice: 1
Enter coefficient: 3
Enter exponent: 3
1. Add more elements
2. Continue
Enter choice: 2


Second polynomial 
Enter coefficient: 6
Enter exponent: 2
1. Add more elements
2. Continue
Enter choice: 1
Enter coefficient: 1
Enter exponent: 1
1. Add more elements
2. Continue
Enter choice: 2

result = p1 + p2
p1 = 4 x^2 + 3 x^3 + 0
p2 = 6 x^2 + 1 x^1 + 0
result = 10 x^2 + 3 x^3 + 1 x^1 + 0
