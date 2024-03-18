#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char mains[100],sc[100],rep[100],cpy[100],res[200];
    int i,j,mc=0,nomc=0;
    
    printf("enter the main string: ");
    scanf("%[^\n]%*c",mains);
    printf("enter the search string: ");
    scanf("%[^\n]%*c",sc);
    printf("enter the replace string: ");
    scanf("%[^\n]%*c",rep);
    strcpy(cpy,mains);
    for(i=0;i<strlen(mains);i++)
    {
        for(j=0;j<strlen(sc);j++)
        {
            if(mains[i+j]==sc[j])
            {
                mc++;
            }
            else
            break;
        }
        if(mc==strlen(sc))
        {
            nomc++;
            strcpy(res,mains);
            strncpy(res+i,rep,strlen(rep));
            strcpy(res+i+strlen(rep),mains+i+strlen(sc));
            strcpy(mains,res);
            i+=strlen(rep)-1;
        }
    }
    printf("the text is\n %s \n",cpy);
    if(nomc>0)
    {
        printf("the replace string is \n %s \n ",res);
    }
    else
    printf("text not found");

}