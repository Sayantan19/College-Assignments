#include<stdio.h>
#include<stdlib.h>

typedef struct Item
{
    float *v;
    float *w;
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
            if(a->vw[i]<a->vw[j])
            {
                temp = a->vw[i];
                a->vw[i] = a->vw[j];
                a->vw[j] = temp;

                temp = a->w[i];
                a->w[i] = a->w[j];
                a->w[j] = temp;
                
                temp = a->v[i];
                a->v[i] = a->v[j];
                a->v[j] = temp;
                
                temp1 = a->index[i];
                a->index[i] = a->index[j];
                a->index[j] = temp1;
            
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
    a->v = (float *) malloc (sizeof(float) * n);
    a->w = (float *) malloc (sizeof(float) * n);
    return a;
}
void Knapsack(float * w1,float * v1,int n, float wt)
{
    item * it = create(it,n);
    for(int i=0;i<n;i++)
    {
        it->vw[i] = (float) v1[i]/w1[i];
        it->w[i] = w1[i];
        it->v[i] = v1[i];
        it->index[i] = i;
    }
    it = BubbleSort(it,n);
    // for(int i=0;i<n;i++)
        // printf("%f\n",it->vw[i]);
    float v2 = 0.0;
    float sum=0.0;
    for(int i=0;i<n;i++)
    {
        float a = (it->w[i] < wt ? it->w[i] : wt);
        sum = sum + a;
        printf("Item %d: %f\n",it->index[i]+1,(a * it->vw[i]/it->v[i]));
        v2 = v2 + (float)(a * it->vw[i]);
        it->w[i] = it->w[i] - a; 
        wt = wt - a;
    }
    printf("%f\n",sum);
    printf("%f\n",v2);
}

int main()
{
    int n;
    float wt;
    printf("Enter the number of item types: ");
    scanf("%d",&n);
    float * w = (float*)malloc (sizeof(float)* n);
    float * v = (float *)malloc (sizeof(float)* n);
    printf("Enter the wt. of the Knapsack: ");
    scanf("%f",&wt);
    for(int i=0;i<n;i++)
    {
        printf("Enter the wt: ");
        scanf("%f",&w[i]);
        printf("Enter the value: ");
        scanf("%f",&v[i]);
    }  
    Knapsack(w,v,n,wt);

}
