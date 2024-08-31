#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int main() {

    int pipefb[2];
    int ret = pipe(pipefb);
    if (ret == -1) {
        perror("pipe");
        exit(-1);
    }

    pid_t pid = fork();
    if (pid > 0) {
        // 父进程
        // read
        // 关闭写段
        close(pipefb[1]);
        char buff[1024] = {0};

        while (read(pipefb[0], buff, sizeof(buff)-1) > 0) {
            printf("%s", buff);
            memset(buff, 0, sizeof(buff));
        }

        wait(NULL);
    } else if (pid == 0) {
        // 子进程
        // write
        // 关闭读段
        close(pipefb[0]);
        // 文件描述符重定向到标准输出
        dup2(pipefb[1], STDOUT_FILENO);
        // 执行命令 ps aux
        execlp("ps", "ps", "aux", NULL);
        perror("execlp");
        exit(0);
    } else {
        printf("fork error!!\n");
    }
    return 0;
}