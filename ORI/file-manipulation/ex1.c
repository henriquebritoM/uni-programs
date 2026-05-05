#include <stdio.h>

int main() {

    FILE *fp = fopen("arq.txt", "w");
    if (fp == NULL) return 1;

    char input;

    while(1) {
        input = fgetc(stdin);
        if (input == '0') break;

        fputc(input, fp);
    }

    fclose(fp);

    fp = fopen("arq.txt", "r");
    if (fp == NULL) return 1;

    while(1) {

        char input = fgetc(fp);
        if (input == EOF) break;

        fputc(input, stdout);
    }

    fclose(fp);

    return 0;

}