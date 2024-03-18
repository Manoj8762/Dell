#include<stdio.h>
void towers(int ,char,char,char);
int main()
{
    int num;
    printf("eneter the number of diskds:\n");
    scanf("%d",&num);
    printf("the sequence of disk moved in tower of hanoi\n ");
    towers(num,'A','B','C');
    printf("\n");
    return 0;
}
void towers(int num,char frompeg,char auxpeg,char topeg)
{
    if(num==1)
    {
        printf("disk move from peg %c\t to peg  %c\t",frompeg,topeg);
        return;
    }
    else
    towers(num-1,frompeg,auxpeg,topeg);
    printf("disk %d move from peg %c\t to peg %c\t:",num,frompeg,topeg);
    towers(num-1,auxpeg,topeg,frompeg);
    return;
}