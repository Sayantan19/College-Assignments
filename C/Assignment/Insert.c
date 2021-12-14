#include <stdio.h>
int main()
{
    int a[100], n,e,pos;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the value to be inserted \n");
    scanf("%d",&e);
    printf("Enter the position you want to insert it in\n");
    scanf("%d",&pos);
    int ins[n+1];
    for(int i=0;i<(n+1);i++)
    {
        if(i==(pos-1))
        ins[i]=e;
        else if(i<(pos-1))
        ins[i]=a[i];
        else if(i>(pos-1))
        ins[i]=a[i-1];
    }
    printf("The array after insertion of the element \n");
    for(int i=0;i<=n;i++)
        printf("%d\t",ins[i]);
}
