#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

pthread_mutex_t onibus_chegou = PTHREAD_MUTEX_INITIALIZER;
sem_t acentos_disponíveis;
pthread_mutex_t mutex_passageiros_esperando = PTHREAD_MUTEX_INITIALIZER;
int passageiros_esperando = 0;
sem_t allboarded; 

void wait_for_bus() {}

void enter_bus() {}

void passanger_thread_entrypoint(*void ) {

    int qtd_passageiros = 70;
    while (qtd_passageiros) {
        sleep(3);
        wait_for_bus();
        enter_bus();
        qtd_passageiros -= 1;
    }
}

void arrive_at_station() {}

void leave_station() {}

void take_passangers() {}

void bus_thread_entrypoint() {

    int qtd_onibus = 10;
    while(qtd_onibus) {
        sleep(17);
        arrive_at_station();
        take_passangers();
        leave_station();
        qtd_onibus -= 1;
    } 
}

int main() {

    ptread_t threads[]

    pthread_create()

    return 0;
}