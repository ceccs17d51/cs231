//Surya Merin Philip
//S3D
//51
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void main()
{
    int cho;
    struct node *temp,*top,*head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=NULL;
    temp->link=NULL;
    head=temp;
    top=head->link;
    do
    {
        
        printf("\nMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nEnter Choice: ");
        scanf("%d",&cho);

        if(cho==1)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            printf("enter the element: ");
            scanf("%d",&temp->data);
            temp->link=head->link;
            head->link=temp;
            top=head->link;
        }
        else if(cho==2)
        {
            if(top==NULL)
            {
                printf("stack is empty!!!");
            }
            else
            {
                printf("popped out: %d",top->data);
                temp=top;
                top=top->link;
                head->link=top;
                free(temp);
            }
        }

        else if(cho==3)
        {
            printf("elements: ");
            temp=top;
            while(temp!=NULL)
            {
                printf("%d ->",temp->data);
                temp=temp->link;
            }
            printf("NULL");
        }
        
    }while(cho==1 || cho==2 || cho==3);
    
}
OUTPUT
MENU
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter Choice: 1
enter the element: 4

MENU
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter Choice: 1
enter the element: 7

MENU
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter Choice: 1
enter the element: 3

MENU
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter Choice: 1
enter the element: 9

MENU
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter Choice: 2
popped out: 9
MENU
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter Choice: 3
elements: 3 ->7 ->4 ->NULL
MENU
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter Choice: 4
]
