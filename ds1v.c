#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define d 7
typedef struct
{
char *dname,*act;
int date;
}dat;
void get(dat *);
void disp(dat *);
void freen(dat *);
dat *cr();
int main()
{
    dat *wk=cr();
     get(wk);
     disp(wk);
     freen(wk);
    return 0;

}
dat *cr()
{
    dat *call=(dat *)malloc(d*sizeof(dat));
    for(int i=0;i<d;i++)
    {
        call[i].dname=NULL;
        call[i].date=0;
        call[i].act=NULL;
    }
    return call;
}
void get(dat *call)
{
    char ch;
    for(int i=0;i<d;i++)
    {
        printf("\n do you want to enter the detaills for day %d is [y/n]: ",i+1);
        scanf("%s",&ch);
        getchar();
        if(tolower(ch)=='n')
        {
            continue;
        }
        printf("day name: ");
        char name[10];
        scanf("%c",&name);
        call[i].dname=strdup(name);
        printf("eneter the date:\n ");
        scanf("% d",&call[i].date);
        printf("enetr the activity: \t");
        char acty[30];
        scanf(" %[^\n]",acty);
        call[i].act=strdup(acty);
    }
    
}
void disp(dat *call)
{
for(int i=0;i<d;i++)
    {
     printf("details for week of day %d",i+1);
     printf("day\n %s:",call[i].dname);
     printf("date%d",call[i].date);
     printf("activity %s",call[i].act);
    }
}
void freen(dat *call)
{
    for(int i=0;i<d;i++)
    {
        free(call[i].dname);
        free(call[i].act);

    }
    free(call);
}