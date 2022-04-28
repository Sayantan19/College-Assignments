#include<stdio.h>
#include<stdlib.h>

typedef struct MaxMin
{
    int max;
    int min;
}maxmin;

maxmin MM(int * arr,int s,int e)
{
    maxmin m,mr,ml;
    if(s==e)
    {
        m.max = arr[e];
        m.min = arr[s];
        return m;
    }
    else
    {

        int mid = (s+e)/2;
        ml = MM(arr,s,mid);
        mr = MM(arr,mid+1,e);
        if(mr.max<ml.max)
            m.max = ml.max;
        else
            m.max = mr.max;
        if(mr.min<ml.min)
            m.min = mr.min;
        else
            m.min = ml.min;
    }
    return m;
}

int main()
{
    int n;
    scanf("%d",&n);
    int *a = (int *) malloc(sizeof(int )*n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    maxmin m = MM(a,0,n-1);
    printf("MAX = %d\n",m.max);
    printf("MIN = %d\n",m.min);
    return 0;
}