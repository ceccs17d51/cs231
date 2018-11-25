#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    char value;
    struct node *link;
};
int issy(char x)
{
    if(x=='+' || x=='-'||x=='*'||x=='/'||x=='('||x==')')
    {
        return 1;
    }   
    else
    {
        return 0;
    }
}
int j=0;
char post[25];
void postfix(struct node *y,struct node *head_op)
{
    if(y->link!=head_op)
    {
        postfix(y->link,head_op);
        post[j]=y->value;
        j++;
    }
    else
    {
        post[j]=y->value;
        j++;
    }
}
void main()
{
    struct node *head_op,*head_sy,*top_op,*top_sy,*temp;
    char infix[25],x;
    int i;
    head_op=(struct node*)malloc(sizeof(struct node));
    head_op->value=0;
    head_op->link=NULL;
    top_op=head_op;
    head_sy=(struct node*)malloc(sizeof(struct node));
    head_sy->value=0;
    head_sy->link=NULL;
    top_sy=head_sy;
    
    printf("Enter the infix form: ");
    scanf("%s",infix);
    for(i=0;i<strlen(infix);i++)
    {
        if(issy(infix[i])==1)
        {
            if(infix[i]==')')
            {
                while(top_sy->value!='(')
                {
                    x=top_sy->value;
                    temp=top_sy;
                    top_sy=top_sy->link;
                    free(temp);
                    temp=(struct node*)malloc(sizeof(struct node));
                    temp->value=x;
                    temp->link=top_op;
                    top_op=temp;
                }
                if(top_sy->value=='(')
                {
                    temp=top_sy;
                    top_sy=top_sy->link;
                    free(temp);
                }
            }
            else
            {
                temp=(struct node*)malloc(sizeof(struct node));
                temp->value=infix[i];
                temp->link=top_sy;
                top_sy=temp;
            }
        }
        else
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->value=infix[i];
            temp->link=top_op;
            top_op=temp;
        }
    }
    
    postfix(top_op,head_op);
    printf("%s",post);
}
