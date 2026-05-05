#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void get_more_populosa(FILE *fp, char nome[40], int *populacao) {

    char n_hab_buffer[10] = {'\0'}; /* Pode aceitar um número com até 10 chars*/
    char nome_buffer[40] = {'\0'}; 

    int n_hab = 0;
    int max_hab = -1;

    while(1) {

        if (fgets(nome, 40, stdin) == NULL) break;
        if (fgets(n_hab_buffer, 10, stdin) == NULL) break;

        n_hab = atoi(n_hab_buffer);

        if (n_hab > max_hab) { 
            max_hab = n_hab;
            strcpy(nome, nome_buffer);
        }
    }
}

int main() {

    char file_name[50] = {'\0'};
    
    fgets(file_name, 50, stdin);
    file_name[strlen(file_name) - 1] = '\0';

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) return 1;

    char nome[50] = {'\0'};
    int populacao = 0;

    get_more_populosa(fp, nome, &populacao);

    printf("A cidade mais populosa é: %s, com %d habitantes\n", nome, populacao);

    fclose(fp);

    return 0;

}