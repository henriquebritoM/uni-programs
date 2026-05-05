#include <stdio.h>
#include <string.h>
#include <ctype.h>

int copy_files_u(FILE *origin, FILE *destiny) {

    char c;

    while (1) {

        c = fgetc(origin);
        if (c == EOF) break;

        c = toupper(c);

        fputc(c, destiny);
    }
}

int main() {

    char file_name[50] = {'\0'};
    fgets(file_name, 49, stdin);
    file_name[strlen(file_name) - 1] = '\0';

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) return 1;
    
    FILE *fp2 = fopen("copia-upper.txt", "w");
    if (fp2 == NULL) return 1;

    copy_files_u(fp, fp2);

    fclose(fp);
    fclose(fp2);

    return 0;

}