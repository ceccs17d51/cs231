//Surya Merin Philip
//S3D
//51
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int exp,coef;
    struct node *link;
};

void main()
{
    struct node *temp,*head,*ptr;
    int e,c,cho;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->exp=0;
    temp->coef=0;
    temp->link=NULL;
    ptr=head;

    do
    {
        printf("Enter coefficient: ");
        scanf("%d",&c);
        printf("Enter exponent: ");
        scanf("%d",&e);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->exp=e;
        temp->coef=c;
        temp->link=NULL;
        ptr->link=temp;
        ptr=ptr->link;
        printf("1. Add  elements\n2. Continue\nEnter choice: ");
        scanf("%d",&cho);
    }while(cho==1);
    printf("1. Display polynomial\n2. Exit\nEnter choice: ");
    scanf("%d",&cho);
    if(cho==1)
    {
        ptr=head->link;
        printf("F(p) = ");
        while(ptr!=NULL)
        {
            printf("%d p%d + ",ptr->coef,ptr->exp);
            ptr=ptr->link;
        }
        printf("0\n");
    }
}
OUTPUT
Enter coefficient: 3
Enter exponent: 2
1. Add  elements
2. Continue
Enter choice: 1
Enter coefficient: 6
Enter exponent: 7
1. Add  elements
2. Continue
Enter choice: 1
Enter coefficient: 6
Enter exponent: 4
1. Add  elements
2. Continue
Enter choice: 2
1. Display polynomial
2. Exit
Enter choice: 1
F(p) = 3 p2 + 6 p7 + 6 p4 + 0
