#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
    pid_t pid = fork();
    if (pid > 0) {
        printf("父进程 pid: %d , ppid: %d \n",getpid(), getppid());
    }
    else {
       printf("子进程 pid: %d , ppid: %d \n",getpid(), getppid()); 
    }
    return 0;
}