#include<stdio.h>
#include<stdlib.h>

typedef struct Item
{
    int *v;
    int *w;
    float *vw;
    int *index;
}item;

item * BubbleSort(item * a,int n)
{
    float temp;
    int temp1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a->vw[i]>a->vw[j])
            {
                temp = a->vw[i];
                a->vw[i] = a->vw[j];
                a->vw[j] = temp;
                
                temp1 = a->index[i];
                a->index[i] = a->index[j];
                a->index[j] = temp1;
                
                temp1 = a->w[i];
                a->w[i] = a->w[j];
                a->w[j] = temp1;
                
                temp1 = a->v[i];
                a->v[i] = a->v[j];
                a->v[j] = temp1;

            }
        }
    }
    return a;
}

item * create(item * a,int n)
{
    a = (item *) malloc (sizeof(item));
    a->vw = (float *) malloc (sizeof(float) * n);
    a->index = (int *) malloc (sizeof(int) * n);
    a->v = (int *) malloc (sizeof(int) * n);
    a->w = (int *) malloc (sizeof(int) * n);
    return a;
}
void Knapsack(int * w,int * v,int n, int wt)
{
    item * it = create(it,n);
    for(int i=0;i<n;i++)
    {
        it->vw[i] = (float) v[i]/w[i];
        it->w[i] = w[i];
        it->v[i] = v[i];
        it->index[i] = i;
    }
    it = BubbleSort(it,n);
    float v1 = 0.0;
    for(int i=0;i<n;i++)
    {
        int a = (it->w[i] < wt ? it->w[i] : wt);
        v1 = v1 + (float)(a * it->vw[i]);
        it->w[i] = it->w[i] - a; 
        wt = wt - a;
    }
    printf("%f",v1);
}

int main()
{
    int n,wt;
    printf("Enter the number of item types: ");
    scanf("%d",&n);
    int * w = (int *)malloc (sizeof(int)* n);
    int * v = (int *)malloc (sizeof(int)* n);
    printf("Enter the wt. of the Knapsack: ");
    scanf("%d",&wt);
    Knapsack(w,v,n,wt);

}