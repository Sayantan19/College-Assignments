#include <bits/stdc++.h>
using namespace std;

int **Generate2AtRandomPosition(int **a)
{
    int i, j;
    do
    {
        i = (rand() % 4);
        j = (rand() % 4);
        if (a[i][j] == 0)
        {
            a[i][j] = 2;
            break;
        }
    } while (true);
    return a;
}

int **GenerateInitialMatrix(int **a)
{
    a = (int **)malloc(sizeof(int *) * 4);
    for (int i = 0; i < 4; i++)
        a[i] = (int *)malloc(sizeof(int) * 4);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            a[i][j] = 0;
    a = Generate2AtRandomPosition(a);
    a = Generate2AtRandomPosition(a);
    return a;
}

int **SlideDown(int **a)
{
    int **b = a;
    int  c = 0;
    for (int j = 3; j >= 0; j--)
    {
        int r = 3;
        for (int i = 0; i <= 3; i++)
        {
            while(r<=0)
            {
                if(b[r][c]==b[i][j]||b[r][c]==0&&b[r-1][c]==0)
                {
                    b[i][j] += b[r][c];
                    b[r][c] = 0;
                }
                r--;
            }
        }
    }
    Generate2AtRandomPosition(b);
    return b;
}

int **SlideUp(int **a)
{
    int **b = a;
    for (int i = 0; i < 4; i++)
    {
        int c = 0;
        for (int j = 0; j < 4; j++)
        {
            int r = 0;
            while (r < 4)
            {
                if (b[r][c] == b[j][i])
                {
                    b[j][i] += b[r][c];
                    b[r][c] = 0;
                }
                r++;
            }
        }
        c++;
    }
    Generate2AtRandomPosition(b);
    return b;
}

int IsGameOver(int **a)
{
    int e, flag = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] == 2048)
            {
                cout << "You Win\n";
                return 1;
            }
            else if (a[i][j] == 0)
                flag++;
        }
    }
    if (flag != 0)
    {
        cout << "Game not yet over. Do you still want to exit?[1/0]: ";
        cin >> e;
        if (e == 1)
            return 1;
        else
            return 0;
    }
    return 1;
}

void display(int **a)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << a[i][j] << "\t";
        cout << "\n";
    }
}
int main()
{
    srand(time(0));
    int **a = GenerateInitialMatrix(a);
    display(a);
    cout << "\n\n";
    a = SlideUp(a);
    display(a);
    cout << "\n\n";
    a = SlideUp(a);
    display(a);
    cout << "\n\n";
    a = SlideUp(a);
    display(a);
    cout << "\n\n";
    a = SlideUp(a);
    display(a);
    cout << "\n\n";
    a = SlideUp(a);
    display(a);
    cout << "\n\n";
    a = SlideUp(a);
    display(a);
    cout << "\n\n";
    if (IsGameOver(a) == 1)
        cout << "Game Over! Thank you!\n";
    return 0;
}