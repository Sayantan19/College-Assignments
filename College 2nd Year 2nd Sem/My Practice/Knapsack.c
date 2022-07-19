#include<stdio.h>
#include<stdlib.h>

typedef struct Item
{
    int * index;
    float * w;
    float * v;
    float * vw;
}item;

item * createKnapsack(int n)
{
    item * i = (item *)malloc(sizeof(item)*n);
    i->index = (int *)malloc(sizeof(int )* n);
    i->w = (float * )malloc(sizeof(float )* n);
    i->v = (float * )malloc(sizeof(float )* n);
    i->vw = (float * )malloc(sizeof(float )* n);
    return i;
}

item * Sort(item * it,int n)
{
    float temp;
    int temp1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(it->vw[j]<it->vw[j+1])
            {
                temp = it->vw[j];
                it->vw[j] = it->vw[j+1];
                it->vw[j+1] = temp;
                
                temp = it->v[j];
                it->v[j] = it->v[j+1];
                it->v[j+1] = temp;
                
                temp = it->w[j];
                it->w[j] = it->w[j+1];
                it->w[j+1] = temp;

                temp1 = it->index[j];
                it->index[j] = it->index[j+1];
                it->index[j+1] = temp1;
            }
        }
    }
    return it;
}

void Knapsack(item * it,float kw,int n)
{
    float rw = kw,netvalue = 0.0;

    for(int i=0;i<n;i++)
    {
        if(it->w[i]<rw)
        {
            netvalue += it->v[i];
            rw -= it->w[i];
            printf("%f weight and %f value of Item no. %d added\n",it->w[i],it->v[i],it->index[i]);
        }
        else
        {
            float a = rw;
            netvalue += (float)a*it->vw[i];
            rw -= rw; 
            printf("%f weight and %f value of Item no. %d added\n",a,(a*it->vw[i]),it->index[i]);
        }
        if(rw==0)
        {
            printf("\nKnapsack filled! Net value of items is %f: ",netvalue);
            break;
        }
    }
}

int main()
{
    int n,kw;
    printf("Enter the number of item types: ");
    scanf("%d",&n);
    printf("Enter the net weight of the Knapsack: ");
    scanf("%d",&kw);
    item * it = createKnapsack(n);
    printf("Enter the details of the items:\n");
    for(int i=0;i<n;i++)
    {
        printf("Index: %d\n",i+1);
        it->index[i] = i+1;
        printf("Value: ");
        scanf("%f",&it->v[i]);
        printf("Weight: ");
        scanf("%f",&it->w[i]);
        it->vw[i] = it->v[i]/it->w[i];
    }
    it = Sort(it,n);
    Knapsack(it,kw,n);
}