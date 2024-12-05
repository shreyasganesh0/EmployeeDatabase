#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
typedef struct{
    unsigned short version;
    unsigned short employees;
    unsigned int filelength;
} database_header;

int main() {
    char* db_file_path = "my-db.db";
    int fd = open(db_file_path, O_RDONLY | O_CREAT, 0644);
    if (fd == -1){
        perror("open");
        return -1;
    }

    database_header* buf;
    int nb = read(fd, buf, sizeof(database_header));
    if (nb!= sizeof(database_header)){
        perror("read");
        close(fd);
        return -1;
    }

    printf("version is %u\n", buf->version);
    printf("number of employees is %u\n", buf->employees);
    printf("filelength is %u\n", buf->filelength);
    return 1;

}
