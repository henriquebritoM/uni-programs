#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

pthread_mutex_t mutex_fila = PTHREAD_MUTEX_INITIALIZER;
sem_t sem_embarcados;
sem_t sem_acentos_disponíveis;
int passageiros_esperando = 0;

void wait_for_bus() {
    //  get a lock = no buses
    //  not get a lock = bus or another passager testing
    
    pthread_mutex_lock(&mutex_fila);
    passageiros_esperando += 1; //  can be more than 50 !
    printf("Passageiro entrou na fila, número %d\n", passageiros_esperando);

    pthread_mutex_unlock(&mutex_fila);

    //  signalize that you are waiting !
    sem_wait(&sem_acentos_disponíveis);
    sem_post(&sem_embarcados);
}


void * passanger_thread_entrypoint(void* nn) {

    //  how many passangers this thread will spawn
    int qtd_passageiros = 18;
    while (qtd_passageiros) {
        sleep(3);
        wait_for_bus();
        qtd_passageiros -= 1;
    }
}

void arrive_at_station() {
    //  lock mutex, so no more passagers
    //  can wait in the line
    pthread_mutex_lock(&mutex_fila);
    printf("\n===================================\n");
    printf("Ônibus chegou na estação!\n");
}

int take_passangers() {
    //  wait until the passagers sinalize they 
    //  all have boarded
    int n_seats = 50;
    int boarded;

    //  Check how many people will enter
    if (passageiros_esperando <= n_seats) {
        boarded = passageiros_esperando;
    }
    else {
        boarded = 50;
    }

    passageiros_esperando -= boarded;

    //  reset the semaphores
    for (int i = 0; i < boarded; i++) {
        sem_post(&sem_acentos_disponíveis);
        sem_wait(&sem_embarcados);
    }

    printf("Subiram %d passageiros, ônibus partindo!\n", boarded);
    return boarded;
}

void leave_station() {
    //  Passagers can now enter the queue again
    printf("\n===================================\n");
    pthread_mutex_unlock(&mutex_fila);
}

void * bus_thread_entrypoint(void* nn) {

    //  how many misses until the thread closes
    //  need to be big, otherwise the passangers thread
    //  will wait forever ! 
    int parted_w_0_passangers = 0;
    while(!parted_w_0_passangers) {
        sleep(17);
        arrive_at_station();
        int boarded = take_passangers();
        if (boarded == 0)
            parted_w_0_passangers = 1;
        leave_station();
    } 
}

int main() {

    sem_init(&sem_embarcados, 1, 0);
    sem_init(&sem_acentos_disponíveis, 1, 50);

    //  0-1 = bus thread
    //  2-9 passangers threads
    pthread_t threads[10];

    pthread_create(&threads[0], NULL, bus_thread_entrypoint, NULL);
    
    for (int i = 1; i < 10; i++) {
        pthread_create(&threads[i], NULL, passanger_thread_entrypoint, NULL);
        sleep(1);
    }

    //  Hope the bus will take everyone
    pthread_join(threads[0], NULL);
    

    //  Hope every thread has finished. Let the SO kill them otherwise >:)

    sem_destroy(&sem_embarcados);
    sem_destroy(&sem_acentos_disponíveis);
    pthread_mutex_destroy(&mutex_fila);

    return 0;
}