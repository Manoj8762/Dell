#include <stdio.h>
void push(int [], int*, int);
int pop(int [], int*);
int main()
{
    int stk[50], i, op1, op2, res;
    char expr[50], symb;
    int top = -1;
    printf("\nEnter a valid postfix expression : \n");
    scanf("%s", expr);
    for(i=0; i<strlen(expr); i++)
        {
        symb = expr[i];
        if(isdigit(symb))
            {
            push(stk, &top, symb-'0');
            }
        else
            {
            op2 = pop(stk, &top);
            op1 = pop(stk, &top);
            switch(symb)
                { 
                case '+' : res = op1 + op2;
                break;
                case '-' : res = op1 - op2;
                break;
                case '*' : res = op1 * op2;
                break;
                case '/' : res = op1 / op2;
                break;
                case '%' : res = op1 % op2;
                break;
                case '^' : res = (int)pow(op1 , op2);
                break;
                }
            push(stk, &top, res);
            }
        }
    res = pop(stk, &top);
    printf("\nValue of %s expression is : %d\n", expr, res);
    return 0;
    }
void push(int Stack[], int *t , int elem)

    {
    *t = *t + 1;
    Stack[*t] = elem;
    }
int pop(int Stack[], int *t)
    {
    int elem;
    elem = Stack[*t];
    *t = *t -1;
    return elem;
    }
