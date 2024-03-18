#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char ph[17], usn[10], name[20], pro[10];
    int  sem;
    struct node* link;
};

typedef struct node* ptr;

ptr get();
void freen(ptr);
ptr inr(ptr);
ptr inf(ptr);
ptr delr(ptr);
ptr delf(ptr);
void disp(ptr);

int main() {
    ptr fi = NULL;
    int ch, num, i;
    printf("Enter n value: ");
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        printf("Enter data for node %d\n", i + 1);
        fi = inf(fi);
    }


    while (1) {
        printf("\nSLL operations\n");
        printf("1. Insert rear\n2. Insert front\n3. Delete front\n4. Delete rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                fi = inr(fi);
                break;
            case 2:
                fi = inf(fi);
                break;
            case 3:
                fi = delf(fi);
                break;
            case 4:
                fi = delr(fi);
                break;
            case 5:
                disp(fi);
                break;
            case 6:
                exit(0);
            default:
                printf("\nEnter valid choice\n");
        }
    }
    return 0;
}

ptr get()
 {
    ptr temp;
    temp = (ptr)malloc(sizeof(struct node));
    printf("\nEnter usn: ");
    scanf("%s", temp->usn);
    printf("Enter name: ");
    scanf("%s", temp->name);
    printf("Enter program: ");
    scanf("%s", temp->pro);
    printf("Enter the sem: ");
    scanf("%d", &(temp->sem));
    printf("Enter your phone number: ");
    scanf("%s",temp->ph);
    temp->link = NULL;
    return temp;
}

void freen(ptr x)
 {
    free(x);
}

ptr inr(ptr fi) 
{
    ptr temp, cur;
    temp = get();
    temp->link = NULL;
    if (fi == NULL)
    {
        return temp;
    }
    cur = fi;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return fi;
}

ptr inf(ptr fi) 
{
    ptr temp;
    temp = get();
    temp->link = fi;
    fi = temp;
    return fi;
}

ptr delr(ptr fi) {
    ptr temp, cur;
    if (fi == NULL) {
        printf("SLL is empty\n");
        return fi;
    }
    cur = fi;
    while (cur->link->link != NULL) 
    {
        cur = cur->link;
    }
    temp = cur->link;
    printf("Node deleted is: %s\n", temp->name);
    freen(temp);
    cur->link = NULL;
    return fi;
}

ptr delf(ptr fi) 
{
    ptr temp;
    if (fi == NULL) {
        printf("SLL is empty\n");
        return fi;
    }
    temp = fi;
    fi = fi->link;
    printf("Node deleted is: %s\n", temp->name);
    freen(temp);
    return fi;
}

void disp(ptr fi) {
    ptr temp;
    int c = 0;
    if (fi == NULL) {
        printf("SLL is empty\n");
        return;
    }
    temp = fi;
    printf("SLL contents are:\n");
    printf("\nUSN\tName\tProgram\tSem\tPhone Number\n");
    while (temp != NULL) {
        printf("%s\t%s\t%s\t%d\t%d\n", temp->usn, temp->name, temp->pro, temp->sem, temp->ph);
        temp = temp->link;
        c++;
    }
    printf("\nSLL has %d nodes\n", c);
}