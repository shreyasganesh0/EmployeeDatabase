#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
 #include <unistd.h>
int main() {
    int fd = open("myfile", O_RDWR | O_CREAT, 0644);
    if (fd == -1){
        perror("open");
        return -1;
    }
    char* buf = "This file is a test\n";
    write(fd, buf, strlen(buf));
}
