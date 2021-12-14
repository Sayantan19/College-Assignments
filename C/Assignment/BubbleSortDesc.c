#include <stdio.h>
int main()
{
    int a[100], n;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    printf("Sorted array in descending order\n");
    for(int i=0;i<n;i++)
        printf("%d \t",a[i]);
}