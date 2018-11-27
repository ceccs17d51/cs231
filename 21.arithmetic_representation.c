#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    char value;
    struct node *link;
};


void main()
{
    struct node *head_op,*top_op,*temp;
    char infix[25],x;
    int i;

    head_op=(struct node*)malloc(sizeof(struct node));
    head_op->value=0;
    head_op->link=NULL;
    top_op=head_op;

    printf("Enter the infix form: ");
    scanf("%s",infix);

    for(i=0;i<strlen(infix);i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->value=infix[i];
        temp->link=top_op;
        top_op=temp;
    }
    temp=top_op;
    while(temp!=head_op)
    {
        printf(" %c ->",temp->value);
        temp=temp->link;
    }    
}
