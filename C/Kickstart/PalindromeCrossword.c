#include<stdio.h>
#include<conio.h>
int main()
{
    // int t;
    // scanf("%d",&t); //Takes the number of test cases
    int n,m;
    //take the number of rows and columns
    printf("Enter rows \n");
    scanf("%d",&n);
    printf("Enter columns \n");
    scanf("%d",&m);
    char puzzle[n][m];
    int s=0; //counts the number of blanks that were filled
    for(int i=0;i<n;i++)
    {
            scanf("%s",&puzzle[i]);
    }
    for(int i=0;i<n;i++)
    {
        char c;
        for(int j=0;j<m;j++)
        {
            if(puzzle[i][j]=='.'&&puzzle[i][j-1]!='#'&&puzzle[i][j]!='.')
            c = puzzle[i][j-1];
            break;
        }
        for(int j=0;j<m;j++)
        {
            if(puzzle[i][j]=='.'&&puzzle[i][j+1]=='#')
            puzzle[i][j] = c;
        }
        s++;
    }
    // for(int i=0;i<m;i++)
    // {
    //     char c1;
    //     for(int j=0;j<n;j++)
    //     {
    //         if(puzzle[i][j]=='.'&&puzzle[i][j-1]!='#')
    //         c1 = puzzle[i-1][j];
    //     }
    //     for(int j=0;j<m;j++)
    //     {
    //         if(puzzle[i][j]=='.'&&puzzle[i+1][j]=='#')
    //         puzzle[i][j] = c1;
    //     }
    //     s++;
    // }
    for(int i=0;i<n;i++)
    {    
        printf("%s",puzzle[i]); //prints the elements
        printf("\n");
    }
}