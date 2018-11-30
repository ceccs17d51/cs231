
//Surya Merin Philip
//S3D
//51



#include<stdio.h>
#include<stdlib.h>

void main()
{
    int arr[40],top1=0,top2=40,cho,i;

    do
    {
        
        printf("\nMENU\n\nSTACK 1        STACK 2");
                printf("\n1.PUSH         4.PUSH");
                printf("\n2.POP          5.POP");   
                printf("\n3.DISPLAY      6.DISPLAY");
                printf("\n         7.EXIT");
                printf("\nEnter Choice: ");
        scanf("%d",&cho);

        if(cho==1)
        {
            top1=top1+1;
            printf("enter the element: ");
            scanf("%d",&arr[top1]);
            printf("element pushed!!!");
        }
        else if(cho==2)
        {
            if(top1==0)
            {
                printf("stack is empty!!!");
            }
            else
            {
                printf("popped out: %d",arr[top1]);
                arr[top1]=NULL;
                top1-=1;
            }
        }
        else if(cho==3)
        {
            printf("elements: ");
            for(i=top1;i>0;i--)
            {
                printf("%d |->",arr[i]);
            }
            printf("NULL");

        }
        

        else if(cho==4)
        {
            top2=top2-1;
            printf("enter the element: ");
            scanf("%d",&arr[top2]);
            printf("element pushed!!!");
        }
        else if(cho==5)
        {
            if(top2==40)
            {
                printf("stack is empty!!!");
            }
            else
            {
                printf("popped out: %d",arr[top2]);
                arr[top2]=NULL;
                top2+=1;
            }
        }
        else if(cho==6)
        {
            printf("elements: ");
            for(i=top2;i<40;i++)
            {
                printf("%d |->",arr[i]);
            }
            printf("NULL");

        }
        
    }while(cho==1 || cho==2 || cho==3 || cho==4 ||cho==5 || cho==6);
    
}
MENU

STACK 1        STACK 2
1.PUSH         4.PUSH
2.POP          5.POP
3.DISPLAY      6.DISPLAY
         7.EXIT
Enter Choice: 1
enter the element: 4
element pushed!!!
MENU

STACK 1        STACK 2
1.PUSH         4.PUSH
2.POP          5.POP
3.DISPLAY      6.DISPLAY
         7.EXIT
Enter Choice: 1
enter the element: 5
element pushed!!!
MENU

STACK 1        STACK 2
1.PUSH         4.PUSH
2.POP          5.POP
3.DISPLAY      6.DISPLAY
         7.EXIT
Enter Choice: 1
enter the element: 8
element pushed!!!
MENU

STACK 1        STACK 2
1.PUSH         4.PUSH
2.POP          5.POP
3.DISPLAY      6.DISPLAY
         7.EXIT
Enter Choice: 2
popped out: 8
MENU

STACK 1        STACK 2
1.PUSH         4.PUSH
2.POP          5.POP
3.DISPLAY      6.DISPLAY
         7.EXIT
Enter Choice: 3
elements: 5 |->4 |->NULL
MENU

STACK 1        STACK 2
1.PUSH         4.PUSH
2.POP          5.POP
3.DISPLAY      6.DISPLAY
         7.EXIT
Enter Choice: 2
popped out: 5
MENU

STACK 1        STACK 2
1.PUSH         4.PUSH
2.POP          5.POP
3.DISPLAY      6.DISPLAY
         7.EXIT
Enter Choice: 4
enter the element: 6
element pushed!!!
MENU

STACK 1        STACK 2
1.PUSH         4.PUSH
2.POP          5.POP
3.DISPLAY      6.DISPLAY
         7.EXIT
Enter Choice: 2
popped out: 4
MENU

STACK 1        STACK 2
1.PUSH         4.PUSH
2.POP          5.POP
3.DISPLAY      6.DISPLAY
         7.EXIT
Enter Choice: 5
popped out: 6
MENU

STACK 1        STACK 2
1.PUSH         4.PUSH
2.POP          5.POP
3.DISPLAY      6.DISPLAY
         7.EXIT
Enter Choice: 6
elements: NULL
MENU

STACK 1        STACK 2
1.PUSH         4.PUSH
2.POP          5.POP
3.DISPLAY      6.DISPLAY
         7.EXIT
Enter Choice: 7
]0;user@user-Inspiron-15-3567: ~/Desktop/a[01;32muser@user-Inspiron-15-3567[00m:[01;34m~/Desktop/a[00m$ exu[Kit
exit
