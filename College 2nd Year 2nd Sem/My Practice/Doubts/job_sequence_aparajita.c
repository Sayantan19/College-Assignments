#include<stdio.h>
#include<stdlib.h>


void jobS(int*, int*, int);

int main()
{
   int i, j, k, n;

   int* deadline;
   int* profit;


   printf("\n enter the number of jobs:");
   scanf("%d", &n);

   profit=(int*)malloc(n*sizeof(int));
   deadline=(int*)malloc(n*sizeof(int));

   printf("\n enter deadlines and profit:\n");
   for(i=0; i<n; i++)
   {
      printf("deadlines    profit\n");
      scanf("%d%d", &deadline[i], &profit[i]);
   }

   jobS(deadline, profit,n);

   return 0;

}

void jobS(int* deadline, int* profit, int n)
{
   int i, j, k;
   int* used;
   //if you initialize max with 0 then it will never change
   int max=deadline[0];
   int profitS=0;

   for(i=0; i<n; i++)
   {
      //max should be less than deadline[i] to update it
      if(max < deadline[i])
         max = deadline[i];
   }

   for(i=0; i<n; i++)
   {
      for(j=i+1; j<n; j++)
      {
         if(profit[i]<profit[j])
         {
            k=profit[i];
            profit[i]=profit[j];
            profit[j]=k;

            //just changing the profit wont help. change the deadlines too.. otherwise you will have problems
            //also, according to your program you do not have anything to keep track of the job number. might
            // cause problems if you are asked to print the sequence
            k=deadline[i];
            deadline[i]=deadline[j];
            deadline[j]=k;
         }
      }
   }

   used=(int*)malloc(max*sizeof(int));
   //added this bit
   for(int i=0;i<max;i++)
      used[i] =0;

   for(i=0; i<n; i++)
   {
      //another problem here. I guess the if statement somehow got deleted. made some changes here
      for(j=deadline[i]-1; j>=0; j--)
      {
         if(used[j]==0)
         {
            printf("profit printed: %d",profit[i]);
            profitS+=profit[i];
            used[j]=1;
            //added this break. it moves out of the loop when it places the particular job
            break;
         }
      }
   }


   printf("\n max profit: %d", profitS);

}
