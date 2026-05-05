#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int count_word(FILE *fp, char word[50]) {

    char word_buffer[50];

    int occurences = 0;
    int word_len = strlen(word);

    while(1) {

        int old_cursor = ftell(fp);
        if (fgets(word_buffer, word_len + 1, fp) == NULL) break;

        if (!strcmp(word, word_buffer)) {
            occurences++;
        }
        else {
            fseek(fp, old_cursor + 1, SEEK_SET); // skip only the first char
        }
    }

    return occurences;
}

int main() {

    char file_name[50] = {'\0'};
    
    fgets(file_name, 50, stdin);
    file_name[strlen(file_name) - 1] = '\0';
    
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) return 1;
    
    char palavra[50];
    fgets(palavra, 50, stdin);
    palavra[strlen(palavra) - 1] = '\0';

    int qtd = count_word(fp, palavra);

    printf("A palavra '%s' aparece %d vezez\n", palavra, qtd);

    fclose(fp);

    return 0;

}