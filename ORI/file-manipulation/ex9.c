#include <stdio.h>
#include <string.h>
#include <ctype.h>

int copy_files(FILE *origin, FILE *destiny) {

    char c;

    while (1) {

        c = fgetc(origin);
        if (c == EOF) break;

        fputc(c, destiny);
    }
}

void merge_files(FILE *origin1, FILE *origin2, FILE *destiny) {

    copy_files(origin1, destiny);
    copy_files(origin2, destiny);
}

int main() {

    char file_name[50] = {'\0'};

    
    fgets(file_name, 50, stdin);
    file_name[strlen(file_name) - 1] = '\0';

    FILE *fp1 = fopen(file_name, "r");
    if (fp1 == NULL) return 1;

    fgets(file_name, 50, stdin);
    file_name[strlen(file_name) - 1] = '\0';
    
    FILE *fp2 = fopen(file_name, "r");
    if (fp2 == NULL) return 1;

    FILE *fp3 = fopen("merged.txt", "w");
    if (fp3 == NULL) return 1;

    merge_files(fp1, fp2, fp3);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;

}