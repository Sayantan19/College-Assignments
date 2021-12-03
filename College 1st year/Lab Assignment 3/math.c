#include<stdio.h>
#include<math.h>
// #include<conio.h>
void max(float a[],int n)
{
    float max=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    printf("%0.2f\n",max);
}

void min(float a[], int n)
{
    float min=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]<min)
            min=a[i];
    }
    printf("%0.2f\n",min);
}

float average(float a[],int n)
{
    float sum=0, avg;
    for(int i=0;i<n;i++)
        sum += a[i];
    avg = sum/n;
    return avg; 
}

void sd(float a[], int n)
{
    float sd;
    float mean = average(a,n);
    for(int i=0;i<n;i++)
    {
        float var = (a[i]-mean)/n;
        if(var>=0.0)
        {
            sd = sqrt(var);
            printf("%0.2f\n",sd);
        }
        else
        {
            sd = sqrt(-var);
            printf("-%0.2f\n",sd);
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    float a[n];
    printf("Enter the elements of the array \n");
    for(int i=0;i<n;i++)
        scanf("%f",&a[i]);
    int c;
    do{
    printf("Enter 1 for finding max\nEnter 2 for finding min\nEnter 3 for finding average\nEnter 4 for finding standard deviation\nEnter your choice");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        max(a,n);
        break;
        case 2:
        min(a,n);
        break;
        case 3:
        printf("%0.2f\n",average(a,n));
        break;
        case 4:
        sd(a,n);
        break;
        default:
        printf("Wrong choice entered \n");
    }
    int choice;
    printf("Do you want to exit?[1/0]\n");
    scanf("%d",&choice);
    if(choice==1)
        break;
    }while(1);
    return 0;
}