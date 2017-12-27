#include "Item.h"

int search_by_name(pItem item[], int item_cnt, const char* szItemName){
    int cursor = 0, i = 0;
    while (i < item_cnt){
        if (item[cursor]->bDetele){
            cursor++;
        }
        else{
            i++;
            if (strcmp(item[cursor]->szItemName, szItemName))
                cursor++;
            else{
                return cursor;
            }
        }
    }
    return -1;
}

void info_init(pItem item[],int *item_cnt){
    FILE *pFile;
    if (NULL ==(pFile = fopen("./items.txt", "r"))){
        *item_cnt = 0;
        return;
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
    int cursor = 0, num = 0;
    while (num < item_cnt)
    {
        if (item[cursor]->bDetele){
            cursor++;
        }
        else{
            num++;
            printf("Item name:%s\n", item[cursor]->szItemName);
            printf("Item price:%d\n", item[cursor]->dPrice);
            cursor++;
        }
    }
}

void myfree(pItem item[],int item_cnt){
    int i = 0, cursor = 0;
    while (i<item_cnt){
        if (item[cursor]->bDetele)
            free(item[cursor++]);
        else{
            free(item[cursor++]);
            i++;
        }
    }
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
    int index = search_by_name(item, item_cnt, szItemName);
    if (index == -1)
        printf("Not found!\n");
    else
        printf("Item price:%d\n", item[index]->dPrice);
}

void info_output(pItem item[], int item_cnt, int i){
    int cursor = 0, num = 0;
    bool isfound = false;
    //printf("cursor:%d\n", cursor);
    while (num < item_cnt)
    {
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
    int index = search_by_name(item, item_cnt, szItemName);
    if (index == -1)
        printf("Not found!\n");
    else{
        printf("Item price to change:");
        scanf("%d", &item[index]->dPrice);
    }
}

void info_delete(pItem item[], int *item_cnt, const char *szItemName){
    int index = search_by_name(item, *item_cnt, szItemName);
    if (index == -1)
        printf("Not found!\n");
    else{
        (*item_cnt)--;
        item[index]->bDetele = true;
    }
}

void info_insert(pItem item[], int *item_cnt){
    int i = 0;
    while(i<*item_cnt){
        if (item[i]->bDetele){
            item[i]->bDetele = false;
            printf("Enter the name of new item: ");
            scanf("%s", item[i]->szItemName);
            getchar();
            printf("Enter the price of new item: ");
            scanf("%d", &item[i]->dPrice);
            getchar();
            (*item)++;
            return;
        }
        else
            i++;
    }
    //printf("%d", i);
    item[i] = (pItem)malloc(sizeof(Item));
    if (item[i]==NULL)
        return;
    item[i]->bDetele = false;
    printf("Enter the name of new item: ");
    scanf("%s", item[i]->szItemName);
    getchar();
    printf("Enter the price of new item: ");
    scanf("%d", &item[i]->dPrice);
    getchar();
    (*item_cnt)++;
    return;
}

void info_flush(pItem item[], int item_cnt){
    FILE *pFile = fopen("./items.txt", "w+");
    if (NULL ==pFile){
        return;
    }
    else{
        if (!item_cnt){
            fprintf(pFile, "0\n");
            fclose(pFile);
            return;
        }
        fprintf(pFile, "%d\n", item_cnt);
        int cursor = 0, num = 0;
        while (num < item_cnt)
        {
            if (item[cursor]->bDetele){
                cursor++;
            }
            else{
                num++;
                fprintf(pFile, "%s ", item[cursor]->szItemName);
                fprintf(pFile, "%d\n", item[cursor]->dPrice);
                cursor++;
            }
        }
    }
    fclose(pFile);
}

void output_help(){
    printf("--------------help--------------\n");
    printf("To insert an item:\n\tinsert\n");
    printf("To delete an item:\n\tdelete <Item-name>\n");
    printf("To output:\n\toutput [index]\t If no index, output all item. Otherwise, output the item by index.\n");
    printf("To search item:\n\tsearch <Item-name>\n");
    printf("To change the item info:\n\tchange <Item-name>\n");
    printf("To save:\t\nsave\n");
    printf("To save and quit:\n\tq\n");
    printf("To display help info:\n\thelp\n");
}

int sort_by_name(const void *a, const void *b){
    //printf("A:%s\nB:%s\n",(*(pItem*)a)->szItemName,(*(pItem*)b)->szItemName);
    return strcmp((*(pItem*)a)->szItemName, (*(pItem*)b)->szItemName);
}

int sort_by_price(const void *a,const void *b){
    return (*(pItem*)b)->dPrice - (*(pItem*)a)->dPrice;
}

void sort(pItem item[], int item_cnt, bool isByname){
    int i = 0, cursor = 0;
    while (i<item_cnt){
        if (item[i]->bDetele){
            cursor = i;
            while((item[++cursor]->bDetele)){}
            /*item[cursor]->bDetele = false;
            item[cursor]->dPrice = item[j]->dPrice;
            strcpy(item[cursor]->szItemName, item[j]->szItemName);
            item[j]->bDetele = false;*/
            pItem tmp=item[cursor];
            item[cursor] = item[i];
            item[i] = tmp;
            i++;
        }
        else{
            cursor++;
            i++;
        }
    }
    /*printf("%s\n", item[0]->szItemName);
        printf("%s\n", item[1]->szItemName);
    printf("%s\n", item[2]->szItemName);

    getchar();*/
    if (isByname)
        qsort(item, item_cnt, sizeof(item[0]), sort_by_name);
    else
        qsort(item, item_cnt, sizeof(item[0]), sort_by_price);
    OutputAll(item,item_cnt);
}