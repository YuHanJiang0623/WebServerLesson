#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

using namespace std;
int main() {
    string path = "/data/ctest/WebServerLesson/part2/fifo/fifo";
    int fd = open(path.c_str(), O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    while (1) {
        char buf[1024];
        int len = read(fd, buf, sizeof(buf));
        if (len < 0) {
            perror("read");
            exit(1);
        } else if (len == 0) {
            printf("server close\n");
            break;
        } else {
            printf("read %d bytes from fifo\n", len);
            printf("content: %s\n", buf);
        }
    }
    close(fd);
    return 0;
}