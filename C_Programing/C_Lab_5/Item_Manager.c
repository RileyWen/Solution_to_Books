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
        
        if (_argv[0]==NULL)
            continue;
        if (!strcmp(_argv[0], "output")){
            if (_argc==1){
                OutputAll(item, item_cnt);
                continue;
            }
            else{
                for (int i = 1; i < _argc; i++)
                    info_output(item, item_cnt, (int)(*_argv[i] - '0'));
                continue;
            }
        }
        if (!strcmp(_argv[0],"search")){
            for (int i = 1; i < _argc; i++)
                info_search(item, item_cnt, _argv[i]);
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
            if (_argc==1){
                printf("Wrong grammer!\n");
                continue;
            }
            else{
                if (!strcmp(_argv[1],"-name")){
                    sort(item, item_cnt, 1);
                    continue;
                }
                if (!strcmp(_argv[1],"-price")){
                    sort(item, item_cnt, 0);
                    continue;
                }
                printf("Wrong grammer!\n");
            }
            continue;
        }
        printf("Not exist command!\n");
    }

    myfree(item, item_cnt);
    return 0;
}