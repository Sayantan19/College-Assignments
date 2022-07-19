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
        printf("This is the parent process.\n");
        printf("Parent process of this process is: %d\n",getpid());
        printf("Child process of this process is:%d\n",p);
    }
    else
    {
        printf("This is the child process.\n");
        printf("Parent process of this process is: %d\n",getppid());
        printf("Child process of this process is: %d\n",getpid());
    }
    return 0;
}