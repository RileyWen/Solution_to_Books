#include <stdio.h>
#include <windows.h>
#include <winnt.h>
int main(int argc,char *argv[]){
    if (argc!=2){
        printf("Parameter amount not correct!");
        exit(-1);
    }
    else
        printf("%s", argv[1]);
    struct _IMAGE_DOS_HEADER IDH;
    
    return 0;
}
