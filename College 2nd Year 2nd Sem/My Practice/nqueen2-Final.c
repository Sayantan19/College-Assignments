#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 10 

int boardList[MAX],count;
void nQueen(int row,int n);
int main()
{
	int n,i,j;
	printf(" - N Queens Problem Using Backtracking -");
	printf("\nEnter number of Queens:");
	scanf("%d",&n);
	
	//Set Initial Value of 
	for(i=0;i<n;++i)
		boardList[i]=-1;
			
	nQueen(0,n);
	return 0;
}

//function for printing the solution
void print(int n)
{
	int i,j;
	printf("\n\nSolution %d:\n\n",++count);
	
	for(i=0;i<n;++i)
		printf("\t%d",i);
	
	for(i=0;i<n;++i)
	{
		printf("\n\n%d",i);
		for(j=0;j<n;++j) //for nxn boardList
		{
			if(boardList[i]==j)
				printf("\tQ"); //queen at i,j position
			else
				printf("\t-"); //empty slot
		}
	}
}

/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
	int i;
	for(i=0;i<row;++i)
	{
		//checking column conflicts
		if(boardList[i]==column && boardList[i]!=-1)
			return 0;
		else //checking digonal conflicts
		{
			if(abs(boardList[i]-column)==abs(i-row))
				return 0;
		}
	}
	
	return 1; //no conflicts
}

//function to check for proper positioning of queen
void nQueen(int row,int n)
{
	int column,i;
	
	for(column=0;column<n;++column)
	{
		printf("\n\nboardList List:  ");
		for(i=0;i<n;++i)
			printf("%d  ",boardList[i]);
		printf("\n");
		printf("\n Try %d Queen at %d column\n",row,column);
		
		if(place(row,column))
		{
			boardList[row]=column; //no conflicts so place queen
			printf("\n %d Queen place at %d column",row,column);
			
			if(row==n-1) //dead end
				print(n); //printing the boardList configuration
			else //try queen with next position
				nQueen(row+1,n);
		}
		else
		{
			printf("\n %d queen under attack at %d column",row,column);
			boardList[row]=-1; //Backtrack
		}
		
	}
}
