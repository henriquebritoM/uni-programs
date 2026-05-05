#include <stdio.h>
#include <string.h>

int count_char(FILE *fp, char c) {

    char i;
    int qtd = 0;
    while(1) {

        i = fgetc(fp);
        if (i == EOF) break;
        
        if (i == c) qtd++;
    }

    return qtd;
}

int main() {

    char file_name[50] = {'\0'};
    fgets(file_name, 49, stdin);
    file_name[strlen(file_name) - 1] = '\0';

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) return 1;

    char c;
    c = fgetc(stdin);

    int qtd = count_char(fp, c);

    fclose(fp);

    printf("O caracter '%c' aparece %d vezes\n", c, qtd);

    return 0;
}
