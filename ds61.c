#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 5
void push();
void pop();
void disp();
char cq[size];
int r=-1,f=0,count=0;
int main()
{
    int ch;
    printf("cq operations:");
    while(1)
    {
        printf("\n1. push \n 2.pop \n 3.display \n 4.exit ");
        printf("enetr your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();break;
            case 2:pop();break;
            case 3:disp();break;
            case 4:exit(0);
            default:printf("enter valid choice");
        }
    }
    return 0;
}
void push()
{
    char ch;
    if (count==size)
    {
        printf("full");

    }
    else
    {
        printf("enetr the element");
        scanf("%c",&ch);
        r=(r+1)%size;
        cq[r]=ch;
        count++;


    }
}
void pop()
{
    if(count==0)
    {
        printf("empty");
    }
    else
    {
        printf("deleted is %c",cq[f]);
        f=(f+1)%size;
        count--;
    }
}
void disp()
{
    int i;
    if(count==0)
    {
        printf("empty");
    }
    
    else
    {
    for(i =0;i<count;i++)
        {
            printf("%c",cq[(f+i)%size]);
        }
        printf("\n");
    }
}