#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char word[21] = {}, largest_word[21] = {}, smallest_word[21] = {127};
int main()
{
    while (printf("Enter word: "),scanf("%s",word)){
        if (strcmp(word,largest_word)>0)
            strcpy(largest_word, word);
        if (strcmp(word,smallest_word)<0)
            strcpy(smallest_word, word);            
        if (strlen(word) == 4)
            break;
    }
    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s", largest_word);
    return 0;
}