 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
#include<ctype.h>

int stk[100],rev[100];
int k,size,top=-1;
void push();
void pop();
void disp();
int pali();

    int main()
    {
        int ch, f;
        printf("enter the size of the stack: ");
        scanf("%d",&size);
        while(1)
        {
            printf("\n 1.push \n 2.pop \n 3.disp  \n 4.palindrome \n 5.exit");
            printf("enter your choice");
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
                {
                    if( f == 1)
                    {
                        printf("palindrome");
                    }
                    else
                    {
                        printf("not palindrome");
                    }
                  
                }
                break;  
                case5:
                exit(0);
                default:printf("enetr valid choice");
            }
        }
        void push()
        {
            int num;
            if(top==size-1)
            {
                printf("stack is full");
            }
            else
            {
                printf("enter the value");
                scanf("%d",&num);
                stk[++top]=num;
            }
        }
        void pop()
        {
            int num;
            if(top==-1)
            {
                printf("stack is empty");
            }
            else
            {
                num = stk[top];
                printf("deleted elemen is %d",num);
                top--;
            }
        }
        void disp()
        {
            int n;
            if(top==-1)
            {
                printf("stack is empty");
            }
            for(n=top;n>=0;n--)
            {
                printf("the element is%d ",stk[n]);
                rev[k++]=stk[n];
            }
        }
        int pali()
        {
            int n,f=1;
            for(n=top;n>=0;n--)
            {
                if(stk[n]!= rev[--k])
                {
                    fa=0;
                }
            }
            return f;
        }
 }
 