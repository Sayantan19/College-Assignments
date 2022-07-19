#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int p;
    p = fork();
    if(p<0)
        printf("Child process creation failed\n");
    else if(p>0)
    {
        printf("\nThis is the parent process.\n");
        printf("\nParent process of this process is: %d\n",getpid());
        printf("\nChild process of this process is:%d\n",p);
    }
    else
    {
        printf("\nThis is the child process.\n");
        printf("\nParent process of this process is: %d\n",getppid());
        printf("\nChild process of this process is: %d\n",getpid());
        sleep(5);
        printf("\nThis is the Orphan process.\n");
        printf("\nParent process of this process is: %d\n",getppid());
        printf("\nChild process of this process is: %d\n",getpid());
    }
    return 0;
}