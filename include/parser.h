#ifndef PARSER_H
#define PARSER_H

#define MAGIC_NUMBER 0x4c4c4141

typedef unsigned int uint_t;
typedef unsigned short us_t;
typedef struct {
    uint_t magic;
    us_t version;
    us_t count;
    uint_t filesize;
} header_t;

typedef struct{
    char* name;
    char* address;
    unit_t phnumber;
} employee_t;


int create_header(header_t** header);
int validate_header(int fd, header_t** header);
int update_file(int fd, header_t** header);

#endif
