#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
    pid_t pid;

    for (size_t i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid == 0) {
            break;
        }
    }

    if (pid > 0) {
        while (1)
        {
            printf("pid: %d\n", pid);
            int st;
            int ret = wait(&st);
            printf("child die pid: %d\n", ret);
            if (ret == -1) {
                break;
            }

            if (WIFEXITED(st)){
                printf("正常退出：%d\n", st);
            }

            if (WIFSIGNALED(st)){
                printf("异常退出 信号为：%d\n", st);
            } 
        }
        
    } else {
        //while (1)
        //{
            printf("pid: %d  ppid: %d\n", pid, getppid());
            sleep(1);
            exit(0);
        //}
    }
    
}
