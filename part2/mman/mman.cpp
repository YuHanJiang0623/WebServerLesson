#include <sys/mman.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main() {

    int fd = open("/data/ctest/WebServerLesson/part2/mman/text.txt", O_RDWR);
    int size = lseek(fd, 0, SEEK_END);

    printf("size: %d\n", size);
    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        strcpy((char *)ptr, "child");
    } else if (pid > 0) {
        wait(NULL);
        char buf[24];
        strcpy(buf, (char *)ptr);
        printf("parent: %s\n", buf);
    }

    munmap(ptr, size);
    return 0;
}