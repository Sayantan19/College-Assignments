#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int global=5;
int main()
{
    int p,local=1;
    p = fork();
    if(p<0)
        printf("Child process creation failed\n");
    else if(p>0)
    {
        // wait(NULL);
        // printf("\nThe child process is now a zombie process\n");
        global++, local++;
        printf("\nThis is the parent process.\n");
        printf("\nParent process of this process is: %d\n",getpid());
        printf("\nChild process of this process is:%d\n",p);
        printf("\nGlobal: %d\tLocal: %d\n",global,local);
    }
    else
    {
        global++, local++;
        printf("\nThis is the child process.\n");
        printf("\nParent process of this process is: %d\n",getppid());
        printf("\nChild process of this process is: %d\n",getpid());
        printf("\nGlobal: %d\tLocal: %d\n",global,local);
    }
    return 0;
}