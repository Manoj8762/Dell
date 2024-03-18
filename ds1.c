#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define d 7
#include<ctype.h>

typedef struct
{
    char *dname;
    int date;
    char *act;

}dat;

void get(dat *);
void disp(dat *);
void freen(dat *);
dat *cr();





int main()
{
    dat *wk = cr();
    get(wk);
    disp(wk);
    freen(wk);
    return 0;


}

dat *cr()
{
    dat *cal=(dat*)malloc( d * sizeof(dat));
    for(int i=0; i<d ;i++)
    {
        cal[i].dname=NULL;
        cal[i].date=0;
        cal[i].act=NULL;
    }
    return cal;

}

void get(dat *cal)
{ 
    char CH;
    printf("enter detalils\n");
    for(int i=0;i<d;i++)
    {
        printf("\n do you want to enter dat for day %d[y/n]\n",i+1);
        scanf("%c",&CH);
        getchar();
        if(tolower(CH)=='n')
        {
            continue;

        }
        printf("\n enter day name \n");
        char name[50];

        scanf("%s",&name);
        cal[i].dname=strdup(name);
        printf("date:");
        scanf("%d",&cal[i].date);
        printf("\n enter activity:");
        char  acty[300];
        scanf(" %[^\n]",&acty);
        cal[i].act=strdup(acty);   



    }
}

void disp(dat *cal)
{
    printf("\n week details\n");
    for(int i=0;i<d;i++)
    {
        printf("%s\n",cal[i].dname);
        printf("%d\n",cal[i].date);
        printf("%s\n",cal[i].act);
        printf("\n");

    }
}

void freen(dat *cal)
{
    for(int i=0;i<d;i++)
    {
        free(cal[i].dname);
        free(cal[i].act);

    }
    free(cal);

}