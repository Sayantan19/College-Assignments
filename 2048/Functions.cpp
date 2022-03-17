#include<bits/stdc++.h>
using namespace std;

int ** Generate2AtRandomPosition(int **a)
{
    int i,j;
    do
    {
        i = (rand()%4);
        j = (rand()%4);
        if(a[i][j]==0)
        {
            a[i][j] = 2;
            break;
        }
    }while(true);
    return a;    
}

int ** GenerateInitialMatrix(int **a)
{
    a = (int **)malloc(sizeof(int *)*4);
    for(int i=0;i<4;i++)
        a[i] = (int *)malloc(sizeof(int)*4);

    for(int i=0;i<4;i++) 
        for(int j=0;j<4;j++)
            a[i][j] = 0;
    a = Generate2AtRandomPosition(a);
    a = Generate2AtRandomPosition(a);
    return a;
}

int IsGameOver(int **a)
{
    int e,flag=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(a[i][j]==2048)
            {
                cout<<"You Win\n";
                return 1;
            }
            else if(a[i][j]==0)
                flag++;
        }
    }
    if(flag!=0)
    {
        cout<<"Game not yet over. Do you still want to exit?[1/0]: ";
        cin>>e;
        if(e==1)
            return 1;
        else
            return 0;
    }
    return 1;
}

int ** SlideDown(int **a)
{
    int **b = a;
    for(int i=0;i<4;i++)
    {
        int r=3,j=0;
        while(r>i&&j!=4)
        {
            if  (b[i][j]!=0)
            {
                if(b[r][j]==0||b[r][j]==b[i][j])
                {
                    b[r][j] += b[i][j];
                    b[i][j]=0;
                    break;
                }
                else
                    r--;
            }
            j++;
        }
    }
    Generate2AtRandomPosition(b);
    return b;
}

void display(int ** a)
{
    for(int i=0;i<4;i++) 
    {
        for(int j=0;j<4;j++)
            cout<<a[i][j]<<"\t";
        cout<<"\n";
    }
}