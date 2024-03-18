#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int stk[100],rev[200];
int k,top=-1,size;
void push();
void pop();
void disp();
int pali();

int main()
{
    int ch,f;

    printf("enter size of stack:");
    scanf("%d",&size);
    while(1)
    {
        printf("stack operations\n");
        printf("1. push \n 2. pop \n 3 . display \n 4. palindrome \n 5. exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)

        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            disp();
            break;
            case 4:
            f=pali();
            if(f==1)
            {
                printf("it is a palindrome\n");

            }
            else
            {
                printf("it is not palindrome\n");

            }
           break;
           case 5:
           exit(0);
           default: printf("enter valid choice\n");

        }
    }
    return 0;
}

void push()
{
    int num;
    if(top==size-1)
    {
        printf("stack is full\n");

    }
    else
    {
        printf("enter value\n");
        scanf("%d",&num);
        stk[++top]=num;
    }
}
void pop()
{
    int n;
    if(top == -1)
    {
        printf("stack is empty\n");

    }
    else{
        n=stk[top];
        printf("deleted number is%d",n);
        top--;

    }
}

void disp()
{
    int n;
    if(top==-1)
    {
        printf("stack is empty\n");

    }
    else
    {
        printf("stack elemnts are:");
        for(n=top;n>=0;n--)
        {
            printf("%d",stk[n]);
            rev[k++]=stk[n];

        }
    }
}

int pali()
{
    int n, fa=1;
    for(n=top;n>=0;n--)
    {
        if(stk[n]!=rev[--k])
        {
            fa=0;

        }

    }
    return fa;
}