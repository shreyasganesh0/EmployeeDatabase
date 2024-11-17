#include <stdio.h>
#include<stdbool.h>
#define MAX_IDS  32

#define MAX_EMPLOYEES 100

struct employee_t{
    int id;
    char firstname[64];
    char lastname[64];
    float salary;
    bool ismanager;
};

union my_union{
    int a;
    float c[10];
};

int main() {

    struct employee_t employees[MAX_EMPLOYEES];
    union my_union unions;
    int i= 0;

    for (i=0; i<MAX_EMPLOYEES; i+=1){
        employees[i].salary = 10.0;
        employees[i].ismanager = false;
    }
    printf("%f\n", employees[10].salary);
    printf("Size of union: %zu bytes\n", sizeof(unions));
}
