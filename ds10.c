#include<stdio.h>
#include<stdlib.h>

struct bst
{
    int data;
    struct bst *left;
    struct bst *right;

};
typedef struct bst node;
node *no;
node* create(node *no, int data)
{
    if(no==NULL)
    {
        node *temp;
        temp=(node*)malloc(sizeof(node));
        temp->data=data;
        temp->left=temp->right=NULL;
        return temp;

    }
    if(data<no->data)
    {
        no->left=create(no->left , data);

    }
    else if(data>no->data)
    {
        no->right=create(no->right ,data);

    }
    return no;

}

node* sc(node *no ,int data)
{
    if(no==NULL)
    {
        printf("node not founf\n");

    }
    else if(data<no->data)
    {
        no->left=sc(no->left ,data);

    }
    else if(data>no->data)
    {
        no->right=sc(no->right,data);

    }
    else
    printf("element found is : %d",no->data);

    
    return no;


}

void in(node *no)
{
    if(no!=NULL)
    {
        in(no->left);
        printf("%d\t",no->data);
        in(no->right);

    }
}







void post(node *no)
{
    if(no!=NULL)
    {
        post(no->left);
        post(no->right);
        printf("%d\t",no->data);
    

    }
}








void pre(node *no)
{
    if(no!=NULL)
    {
        printf("%d\t",no->data);
        pre(no->left);
        pre(no->right);

    }
}


int main()
{
    int data,ch,i,n;
    node *root=NULL;
    while(1)
    {
        printf("\n 1. insertion \n 2. search \n 3. inorder \n 4. postorder \n 5. preorder \n 6. exit ");
        printf("\n enter your choice \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("enter n value\n");
            scanf("%d",&n);
            printf("\n enter the  value to create bst\n");
            for(i=0;i<n;i++)
            {
                scanf("%d",&data);
                root=create(root , data);

            }
            break;
            case 2:
            printf("enter key element to be searched\n");
            scanf("%d",&data);
            root=sc(root,data);
            break;
            case 3:
            in(root);
            break;
            case 4:
            post(root);
            break;
            case 5:
            pre(root);
            break;
            case 6:
            exit(0);

        }
    }
}