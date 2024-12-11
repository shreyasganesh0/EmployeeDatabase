#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <stdbool.h>
int main(int argc , char* argv[]) {
    bool newfile = false;
    char* filepath = NULL;
    int c;
    while((c = getopt(argc, argv, "nf:") != -1)){
        switch (c){
        case 'n':{
           newfile = true; 
        }
           break;
        case 'f':{
           filepath = optarg; 
        }
           break;
        case '?':{
            printf("Unkown arg %s", optarg);
        }
        case ':':{
            printf("Missing option argument");
        }
        default:
            return -1;
        }
    }
    if (newfile){
        printf("newfile path is: %s", filepath);
    }
    return 0;
}
    
