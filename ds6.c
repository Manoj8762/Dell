#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 5

char cq[size];
int f = 0, r = -1;
int count = 0;

void push();
void pop();
void disp();

int main() {
    int ch;
    while (1) {
        printf("cq operation\n");
        printf("1. push\n2. pop\n3. display\n4. exit\n");
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch) {
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
                exit(0);
            default:
                printf("\nenter valid choice\n");
        }
    }
    return 0;
}

void push() {
    char ch;
    if (count == size) 
    {
        printf("cq is full\n");

    }
     else {
        printf("enter element to be insert:");
        scanf(" %c", &ch); // Notice the space before %c to consume newline character
        r = (r + 1) % size;
        cq[r] = ch;
        count++;
    }
}

void pop() {
    if (count == 0) {
        printf("queue is empty\n");
    } else {
        printf("element deleted is: %c\n", cq[f]);
        f = (f + 1) % size;
        count--;
    }
}

void disp() {
    int i;
    if (count == 0) 
    {
        printf("cq is empty\n");
    }
     else 
    {
        printf("cq elements are:\n");
        for (i = 0; i < count; i++) 
        {
            printf("%c ", cq[(f + i) % size]);
        }
        printf("\n");
    }
}