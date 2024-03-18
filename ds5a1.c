#include<stdio.h>
#include<math.h>
void push(int[],int *,int);
int pop(int [],int *);
int main()
{
    int stk[50],i,top=-1,op1,op2,res;
    char expr[50],symb;
    printf("enter the postfix expression :");
    scanf("%s",expr);
    for (i=0;i<strlen(expr);i++)
    {
        symb=expr[i];
        if(isdigit(symb))
        {
            push(stk,&top,symb-'\0');

        }
        else
        {
            op2=pop(stk,&top);
            op1=pop(stk,&top);
            switch(symb)
            {
                case'+':res=op1+op2;
                break;
                 case'-':res=op1-op2;
                break;
                 case'*':res=op1*op2;
                break;
                 case'/':res=op1/op2;
                break;
                 case'%':res=op1%op2;
                break;
                 case'^':res=(int)pow(op1,op2);
                break;
            }
            push(stk,&top,res);
        }
        
    }
    res=pop(stk,&top);
    printf("value of %s expressin is %d",expr,res);
    return 0;
}
void push(int stack[],int *t,int elem)
{
    *t=*t+1;
    stack[*t]=elem;
}
int pop(int stack[],int *t)

{
    int elem;
    elem=stack[*t];
    *t=*t-1;
    return elem;
}