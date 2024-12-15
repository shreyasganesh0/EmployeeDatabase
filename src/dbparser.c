#include <fcntl.h>
#include <stdio.h>
#include "parser.h"
#include <arpa/inet.h>
#include <sys/stat.h>


int create_header(header_t** header){
    header_t* tempheader = calloc(1, sizeof(header_t));
    if !tempheader{
        printf("Malloc failed during creation");
        return -1;
    }

    tempheader->magic = MAGIC_NUMBER;
    tempheader->version = 0x1;
    tempheader->count = 0;
    tempheader->filesize = sizeof(header_t);

    *header = tempheader;

    return 0;
}

int validate_header(int fd, header_t** header){
    if (fd<0){
        printf("invalid file from user");
        return -1;
    }
    header_t* tempheader = calloc(1,sizeof(header_t));
    if (!tempheader){
        printf("Allocation of buffer failed in validation");
        return -1;
    }


    if (read(fd, tempheader,sizeof(tempheader))!= sizeof(header_t)){
        perror("read");
        free(tempheader);
        return -1;
    }

    tempheader->version = ntohs(*header->version);
    tempheader->magic = ntohs(*header->magic);
    tempheader->filesize = ntohl(*header->filesize);
    tempheader->count = ntohl(*header->count);
    
    if(header->magic != MAGIC_NUMBER){
        printf("Error with magic number");
        return -1;
    }

    if(header->version != 1){
        printf("Error with version");
        return -1;
    }

    struct stat dbstat = {0};
    fstat(fd, &dbstat); 
    if(header->filesize != dbstat->st_size ){
        printf("Filesize mismatch");
        return -1;
    }

    *header = tempheader;
    return 0;
}

int update_file(int fd, header_t* header, employee_t* employee){
    if (fd<0){
        printf("Invalid file to write to");
        return -1;
    }

    int employeecount = header->count;

    header->magic = htonl(header->magic);
    header->version = htons(header->version);
    header->count = htons(header->count);
    header->filesize = htonl(sizeof(header_t) + sizeof(employee_t)*employeecount);
    
    lseek(fd, 0, SEEK_SET);

    write(fd, header, sizeof(header_t));

    for(;i<count;i++){
        write(fd, employee[i], sizeof(employee_t));
    }

    return 0;
}
