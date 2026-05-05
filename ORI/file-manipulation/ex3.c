#include <stdio.h>
#include <string.h>

int count_vogals(FILE *fp) {

    char i;
    int vogais = 0;
    while(1) {

        i = fgetc(fp);
        if (i == EOF) break;
        
        switch (i)
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
            vogais++;
            break;
        }
    }

    return vogais;
}

int main() {

    char file_name[50] = {'\0'};
    fgets(file_name, 49, stdin);
    file_name[strlen(file_name) - 1] = '\0';

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) return 1;

    int n_vogals = count_vogals(fp);

    fclose(fp);

    printf("Número de vogais: %d\n", n_vogals);

    return 0;

}