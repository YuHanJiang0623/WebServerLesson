#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

using namespace std;
int main()
{
    string path = "/data/ctest/WebServerLesson/part2/fifo/fifo";
    int ret = access(path.c_str(), F_OK);
    if (ret == -1) {
        int ret = mkfifo(path.c_str(), 0664);
        if (ret == -1) {
        perror("mkfifo");
        exit(0);
        }
    }

    int fd = open(path.c_str(), O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(0);
    }

    while (1) {
        char buf[1024] = {0};
        sprintf(buf, "hello world %d", rand() % 100);
        write(fd, buf, strlen(buf));
        sleep(1);
    }

    close(fd);
    return 0;
}