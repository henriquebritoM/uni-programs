#include <stdio.h>
#include <string.h>

int count_lines(FILE * fp) {

    char i;
    int n_lines = 0;
    while(1) {

        i = fgetc(fp);
        if (i == EOF) break;
        if (i == '\n') n_lines++;
    }

    return n_lines;
}

int main() {

    char file_name[50] = {'\0'};
    fgets(file_name, 49, stdin);
    file_name[strlen(file_name) - 1] = '\0';

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) return 1;

    int n_lines = count_lines(fp);

    fclose(fp);

    printf("Número de linhas: %d\n", n_lines);

    return 0;

}