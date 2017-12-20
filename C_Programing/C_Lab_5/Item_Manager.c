#include "Item.h"
int main(){
    char command[255], *argv[255];
    pItem item[255];
    int item_cnt = 0, argc = 0;

    info_init(item, &item_cnt);
    printf("Welcome to Item Manager!\nEnter 'q' to save and quit\n");
    while (1){
        printf("> ");
        gets(command);
        parse_command(command, &argc, argv);
        //for (int i = 0; i< argc;i++)
        //    printf("%s", argv[i]);
        if (!strcmp(argv[0], "output")){
            if (argc==1){
                OutputAll(item, item_cnt);
                continue;
            }
            else{
                info_output(item, item_cnt, (int)(*argv[1] - '0'));
                continue;
            }
        }
        if (!strcmp(argv[0],"search")){
            info_search(item, item_cnt, argv[1]);
            continue;
        }
        if (!strcmp(argv[0],"q"))
            break;
        if (!strcmp(argv[0],"change")){
            info_change(item, item_cnt, argv[1]);
            continue;
        }
    }
    //gets(command);
    myfree(item, item_cnt);
    return 0;
}