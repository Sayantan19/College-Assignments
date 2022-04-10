#include<stdio.h>
#include<stdlib.h>

void Tower(int,char,char,char);

int main()
{
    int n;
    printf("Enter a value between 0 and 3: ");
    scanf("%d",&n);
    char from = 'A',to = 'C',aux = 'B';
    Tower(n,from,to,aux);
}

void Tower(int n,char from,char to,char aux)
{
    if(n==0)
        return;
    Tower(n-1,from,aux,to);
    printf("Disk %d moved from %c to %c\n",n,from,aux);
    Tower(n-1,from,to,aux);
}
