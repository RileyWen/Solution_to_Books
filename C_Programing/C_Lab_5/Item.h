#ifndef _ITEM_H
#define _ITEM_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _Item{
    bool bDetele;
    int dPrice;
    char szItemName[255];
}Item,*pItem;

void info_init(pItem item[],int *item_cnt);
void OutputAll(pItem item[], int item_cnt);
void myfree(pItem item[],int item_cnt);
void parse_command(char command[], int *argc, char *argv[]);
void info_search(pItem item[], int item_cnt, const char *szItemName);
void info_output(pItem item[], int item_cnt, int i);
void info_change(pItem item[], int item_cnt, const char *szItemName);
void info_delete(pItem item[], int *item_cnt, const char *szItemName);
void info_insert(pItem item[], int *item_cnt);
void info_flush(pItem item[], int item_cnt);

#endif
