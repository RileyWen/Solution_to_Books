#include "Item.h"
int main(int argc,char **argv){
    char command[255], *_argv[255];
    pItem item[255]={0};
    int item_cnt = 0, _argc = 0;

    info_init(item, &item_cnt);
    printf("Welcome to Item Manager!\n");
    output_help();
    while (1){
        printf("> ");
        gets(command);
        parse_command(command, &_argc, _argv);
        //for (int i = 0; i< _argc;i++)
        //    printf("%s", _argv[i]);
        if (_argv[0]==NULL)
            continue;
        if (!strcmp(_argv[0], "output")){
            if (_argc==1){
                OutputAll(item, item_cnt);
                continue;
            }
            else{
                info_output(item, item_cnt, (int)(*_argv[1] - '0'));
                continue;
            }
        }
        if (!strcmp(_argv[0],"search")){
            info_search(item, item_cnt, _argv[1]);
            continue;
        }
        if (!strcmp(_argv[0],"q")){
            info_flush(item, item_cnt);
            break;
        }
        if (!strcmp(_argv[0],"change")){
            info_change(item, item_cnt, _argv[1]);
            continue;
        }
        if (!strcmp(_argv[0],"insert")){
            info_insert(item, &item_cnt);
            continue;
        }
        if (!strcmp(_argv[0],"delete")){
            info_delete(item, &item_cnt, _argv[1]);
            continue;
        }
        if (!strcmp(_argv[0],"save")){
            info_flush(item, item_cnt);
            continue;
        }
        if (!strcmp(_argv[0],"help")){
            output_help();
            continue;
        }
        if (!strcmp(_argv[0],"sort")){
            sort(item, item_cnt, 1);
            continue;
        }
        printf("Not exist command!\n");
    }
    //info_flush
    //gets(command);
    myfree(item, item_cnt);
    return 0;
}