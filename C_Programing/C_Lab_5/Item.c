#include "Item.h"

void info_init(pItem item[],int *item_cnt){
    FILE *pFile;
    if (NULL==(pFile = fopen(".\\items.txt", "r"))){
        *item_cnt = 0;
    }
    else{
        fscanf(pFile, "%d", item_cnt);
        for (int i = 0; i < *item_cnt; i++){
            item[i] = (pItem)malloc(sizeof(Item));
            item[i]->bDetele = false;
            fscanf(pFile, "%s%d", item[i]->szItemName, &item[i]->dPrice);
        }
    }
    fclose(pFile);
}

void OutputAll(pItem item[],int item_cnt){
    if (!item_cnt){
        printf("No item!\n");
        return;
    }
    for (int i = 0; i < item_cnt; i++){
       printf("Item %d\n\tItem name:%s\n\tItem price:%d\n", i+1, item[i]->szItemName, item[i]->dPrice);
    }
}

void myfree(pItem item[],int item_cnt){
    for (int i = 0; i < item_cnt; i++)
        free(item[i]);
}

void parse_command(char command[],int *argc,char *argv[]){
    char *delim, *buf = command;
    buf[strlen(buf)] = ' ';
    buf[strlen(buf) + 1] = '\0';
    while (*buf && (*buf == ' '))
        buf++;

    *argc = 0;
    while ((delim = strchr(buf, ' '))){
        argv[(*argc)++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' '))
            buf++;
    }
    argv[*argc] = NULL;
}

void info_search(pItem item[], int item_cnt, const char* szItemName){
    int cursor = 0, i = 0;
    bool isfound = false;
    while (i < item_cnt){
        if (item[cursor]->bDetele){
            cursor++;
        }
        else{
            i++;
            if (strcmp(item[cursor]->szItemName, szItemName))
                cursor++;
            else{
                printf("Item price:%d\n", item[cursor]->dPrice);
                isfound = true;
                break;
            }
        }
    }
    if (!isfound)
        printf("Not Found\n");
}

void info_output(pItem item[], int item_cnt, int i){
    int cursor = 0, num = 0;
    bool isfound = false;
    while (num < item_cnt){
        if (item[cursor]->bDetele){
            cursor++;
        }
        else{
            num++;
            if (num==i){
                printf("Item name:%s\n", item[cursor]->szItemName);
                printf("Item price:%d\n", item[cursor]->dPrice);
                isfound = true;
                break;
            }
        }
    }
    if (!isfound)
        printf("Not Found\n");
}

void info_change(pItem item[], int item_cnt, const char* szItemName){
    int cursor = 0, i = 0;
    bool isfound = false;
    while (i < item_cnt){
        if (item[cursor]->bDetele){
            cursor++;
        }
        else{
            i++;
            if (strcmp(item[cursor]->szItemName, szItemName))
                cursor++;
            else{
                printf("Item price to change:");
                scanf("%d", &item[cursor]->dPrice);
                isfound = true;
                break;
            }
        }
    }
    if (!isfound)
        printf("Not Found\n");
}