#include <string.h>
#include <stdio.h>

int main() {
    char mains[200], sc[200], rep[200], res[400],cpy[200];

    int i, j, mc, nom;
    nom = 0;

    printf("Enter main string\n");
    scanf("%199[^\n]%*c", mains);
    printf("Enter search string\n");
    scanf("%199[^\n]%*c", sc);
    printf("Enter replace string\n");
    scanf("%199[^\n]%*c", rep);
    strcpy(cpy,mains);

    for (i = 0; i <= strlen(mains) - strlen(sc); i++) 
    {
        mc = 0;
        for (j = 0; j < strlen(sc); j++) 
        {
            if (mains[i + j] == sc[j]) 
            {
                mc++;
            } 
            else
            {
                break;
            }
        }
        if (mc == strlen(sc)) 
        {
            nom++;
            strcpy(res, mains);
            strncpy(res + i, rep, strlen(rep));
            strcpy(res + i + strlen(rep), mains + i + strlen(sc));
            strcpy(mains, res);
            i += strlen(rep) - 1;
        }
    }

    printf("Input text is\n%s\n", cpy);
    if (nom > 0) 
    {
        printf("Replaced text is\n%s\n", res);
    } else 
    {
        printf("Search string not found\n");
    }

    return 0;
}