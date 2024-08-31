#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>

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
        char buff[1024] = {0};
        int len = read(pipefb[0], buff, sizeof(buff));

        printf("read recv : %s pid : %d\n", buff, getpid());
    } else if (pid == 0) {
        // 子进程
        // write
        const char *str = "hello";
        write(pipefb[1], str, strlen(str));
    } else {
        printf("fork error!!\n");
    }
    return 0;
}