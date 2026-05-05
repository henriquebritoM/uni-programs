#include <stdio.h>
#include <string.h>

void count_letters_indv(FILE *fp, int arr[26]) {

    char i;
    while(1) {

        i = fgetc(fp);
        if (i == EOF) break;
        
        if (i >= 65 && i <= 90) {
            arr[i - 65]++;
        }
        else if (i >= 97 && i <= 122) {
            arr[i - 97]++;
        }
    }
}

int main() {

    char file_name[50] = {'\0'};
    fgets(file_name, 49, stdin);
    file_name[strlen(file_name) - 1] = '\0';

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) return 1;

    int arr[26] = {0};

    count_letters_indv(fp, arr);

    fclose(fp);

    for (int i = 0; i < 26; i++) {
        printf("'%c' = %d\n", i+97, arr[i]);
    }

    return 0;
}
