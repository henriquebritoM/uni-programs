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

int count_letters(FILE *fp) {

    char i;
    int letters = 0;
    while(1) {

        i = fgetc(fp);
        if (i == EOF) break;
        
        if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122)) {
            letters++;
        }
    }

    return letters;
}

int main() {

    char file_name[50] = {'\0'};
    fgets(file_name, 49, stdin);
    file_name[strlen(file_name) - 1] = '\0';

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) return 1;

    int n_letters = count_letters(fp);
    fseek(fp, 0, SEEK_SET); //  Returns the cursor to the start
    int n_vogals = count_vogals(fp);

    fclose(fp);

    /* This method with two O(n) is not ideal, it could be done with just one */
    printf("Número de vogais: %d\n", n_vogals);
    printf("Número de consoantes: %d\n", n_letters - n_vogals);

    return 0;
}
