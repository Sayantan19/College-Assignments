#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int l, int m, int r)
{
    int i, j, k;
    int *arr;
    arr = (int *)malloc(sizeof(int) * (r - l) + 1);
    int n1 = m - l + 1, n2 = r - m;
    int a1[n1], a2[n2];
    for (i = 0; i < n1; i++)
        a1[i] = a[l + i];
    for (j = 0; j < n2; j++)
        a2[j] = a[l + j];
    i = 0;
    j = 0;
    k = 1;
    while (i < n1 && j <= n2)
    {
        if (a1[i] < a2[j])
        {
            arr[k] = a1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = a2[j];
            j++;
            k++;
        }
    }

    while (j < n2)
    {
        arr[k] = a[j];
        j++;
        k++;
    }
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
}

void MergeSort(int *a, int l, int r)
{
    if (l < r)
    {
        int m = l + (r-1) / 2;
        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int a[5] = {4, 2, 5, 3, 1};
    MergeSort(a, 0, 5);
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}