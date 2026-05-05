#include <stdio.h>
#include <string.h>

int is_vogal(char c) {
    int r = 0;

    switch (c)
    {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
        r = 1;
        break;
    }

    return r;
}

int copy_files(FILE *origin, FILE *destiny) {

    char i;

    while (1) {

        i = fgetc(origin);
        if (i == EOF) break;

        if (is_vogal(i)) fputc('*', destiny);
        else fputc(i, destiny);
    }
}

int main() {

    char file_name[50] = {'\0'};
    fgets(file_name, 49, stdin);
    file_name[strlen(file_name) - 1] = '\0';

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) return 1;
    
    FILE *fp2 = fopen("copia.txt", "w");
    if (fp2 == NULL) return 1;

    copy_files(fp, fp2);

    fclose(fp);
    fclose(fp2);

    return 0;

}