#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[10],usn[10],dep[10],des[10];
    int sal;
    struct node *plink;
    struct node *nlink;
    };
    typedef struct node* ptr;
    ptr get();
    void freen(ptr);
    ptr inr(ptr);
    ptr inf(ptr);
    ptr delr(ptr);
    ptr delf(ptr);
    void disp(ptr);

    int main()
    {
        ptr fi=NULL;
        int ch,num,i;
        printf("enter n value\n");
        scanf("%d",&num);
        for (i=0;i<num;i++)
        {
            fi=inf(fi);

        }
       while(1)
       {
        printf("\n dll ope");
        printf("\n 1.inr\n 2. inf\n 3. delf \n 4. delr \n 5 . display\n 6. exit\n");
        printf("enter ur choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
            fi=inr(fi);
            break;
            case 2:
            fi=inf(fi);
            break;
            case 3:
            fi=delf(fi);
            break;
            case 4:
            fi=delr(fi);
            break;
            case 5:
            disp(fi);
            break;
            case 6:
            exit(0);
            default:printf("\nlkb");


        }
    }
    return 0;
    }
    void freen(ptr x)
    {
        free(x);
    }




    ptr get()
    {
        ptr new;
        new=(ptr)malloc(sizeof(ptr));

        printf("\n enter ur nm:");
        scanf("%s",new->name);
        printf("\nenter ur usn:");
        scanf("%s",new->usn);
        printf("\nenter your dept:");
        scanf("%s",new->dep);
        printf("\nenter ur design:");
        scanf("%s",new->des);
        printf("enter ur sal:");
        scanf("%d",&new->sal);
        return new;
}


ptr inr(ptr fi)
{
    ptr c, t;
    t=get();
    t->nlink=NULL;
    t->plink=NULL;
    if(fi==NULL)
    {
        return t;
    }
   c=fi;
   while(c->nlink!=NULL)
   {
    c=c->nlink;
   }
   c->nlink=t;
   t->plink=c;
   return fi;
}

ptr inf(ptr fi)
{
    ptr t;
    t=get();
    t->plink=NULL;
    t->nlink=NULL;

    t->nlink=fi;
    fi=t;
    return fi;
}

ptr delr(ptr fi)
{
    ptr temp , cur;
    if(fi==NULL)
    {
        printf("\nempty");

    }

    cur=fi;
    if(cur->nlink=NULL)
    {
        printf("node deleted is %s",cur->name);
        freen(cur);
    }
    while(cur->nlink!=NULL)
    {
        cur=cur->nlink;

    }
    temp=cur->plink;
    temp->nlink=NULL;
    printf("\n node deleted is %s",cur->name);
    freen(cur);
    return fi;

}
ptr delf(ptr fi)
{
    ptr temp;
    if(fi==NULL)
    {
        printf("empty\n");

    }
    temp=fi;
    if(temp->nlink=NULL)
    {
        printf("\n node deleted is %s",temp->name);
        freen(temp);

    }
    fi=fi->nlink;
    fi->plink=NULL;
    printf("\nnode deleted is %s",temp->name);
    freen(temp);

}

void disp(ptr fi)
{
    ptr cu;
    int c=0;
    if(fi==NULL)
    {
        printf("\n  empty");

    }
    printf("\ndll contents");
    printf("\n usn\tnsme\tdept\nsesign\tsalery\n");
    cu=fi;
    while(cu!=NULL)
    {
        printf("%s\t%s\t%s\t%s\t%d",cu->usn,cu->name,cu->dep,cu->des,cu->sal);
        cu=cu->nlink;
        c++;
    }
    printf("total nodes %d",c);

}