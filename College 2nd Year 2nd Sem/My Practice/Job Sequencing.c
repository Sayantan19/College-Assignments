#include <stdio.h>
#include <stdlib.h>

typedef struct Job
{
    int *no;
    int *deadline;
    int *profit;
} job;

//To sort according to the decreasing order of profit
job *BubbleSort(job *, int);
//Function to perform the operation
void JobSequencing(job *, int);

//Driver function
int main()
{
    int n;
    printf("Enter the number of jobs in line: ");
    scanf("%d",&n);
    job * j = (job *) malloc(sizeof(job));
    for(int i=0;i<n;i++)
    {
        j->no = (int *) malloc (sizeof(int)*n);
        j->profit = (int *) malloc (sizeof(int)*n);
        j->deadline = (int *) malloc (sizeof(int)*n);
    }

    printf("Enter the job details\n");
    for(int i=0;i<n;i++)
    {
        printf("Job %d:\n",(i+1));
        j->no[i] = i+1;
        printf("Profit: ");
        scanf("%d",&j->profit[i]);
        printf("Deadline: ");
        scanf("%d",&j->deadline[i]);
    }   
    j = BubbleSort(j,n);
    JobSequencing(j,n);
}

job *BubbleSort(job *j, int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n-i-1;k++)
        {
            if(j->profit[k]<j->profit[k+1])
            {
                temp = j->profit[k+1];
                j->profit[k+1] = j->profit[k];
                j->profit[k] = temp;

                temp = j->deadline[k+1];
                j->deadline[k+1] = j->deadline[k];
                j->deadline[k] = temp;

                temp = j->no[k+1];
                j->no[k+1] = j->no[k];
                j->no[k] = temp;
            }
        }
    }

    //This I did to check whether the Jobs were coming out in the sorted order of their profits or not
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\n",j->no[i],j->deadline[i],j->profit[i]);
    return j;
}

void JobSequencing(job *j, int n)
{
    int *seq, max = j->deadline[0],sum =0;

    // allots the maximum number of jobs that can be done to the seq array
    for (int i = 0; i < n; i++)
    {
        if (j->deadline[i] > max)
            max = j->deadline[i];
    }

    seq = (int *)malloc(sizeof(int) * max);

    for (int i = 0; i < max; i++)
        seq[i] = 0;

    // this outer loop will traverse through each element of the sorted array
    for (int i = 0; i < n; i++)
    {
        // this loop will traverse from the deadline to the start position to check for available slots.
        // if available, then the value will be seq[k] will be replaced with the job number
        for (int k = j->deadline[i]-1; k >= 0; k--)
        {
            if (seq[k] == 0)
            {
                seq[k] = j->no[i];
                sum += j->profit[i];
                break;
            }
        }

        // this checks whether the sequence array is full or not. if full, then it wil break away from the loop
        // as there are no jobs that can be accommodated
        int flag = 0;
        for (int k = 0; k < max; k++)
        {
            if (seq[k] == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            break;
    }

    // prints the job list
    for (int i = 0; i < max; i++)
        if(seq[i]!=0)
            printf("J%d ", seq[i]);
    
    //prints the net profit
    printf("\nNet profit: %d",sum);
}