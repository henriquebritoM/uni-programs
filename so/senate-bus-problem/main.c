#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int bus_capacity;   //  semaphore with 50 spaces
int riders;         //  each thread has a random timer that waits the bus
int has_arrived;    //  a mutex maybe

//  Possible to use try lock and only lock if it failed
//  why? because if it has already arrived, the rider cannot enter

sem_t bus_capacity;
sem_t riders_waiting;   // can be increased only if not arrived
pthread_mutex_t bus = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t has_arrived = PTHREAD_MUTEX_INITIALIZER;

void send_bus(void *arg) {
    //  random in [3, 10]
    // int interval = rand() % (10 - 3 + 1) + 3;
    //  random in [30, 50]
    // int capacity = rand() % (50 - 20 + 1) + 20;

    int someone_waiting = 1;
    
    //  Loop do ônibus chegando e saindo
    sem_init(&bus_capacity, 0, 50);

    while(someone_waiting) {
        sleep(5); //    riders can lock now
        
        pthread_mutex_lock(&has_arrived);   //  riders can no longer lock

        someone_waiting = sem_trywait(&riders_waiting);  
        
        depart();

        pthread_mutex_unlock(&has_arrived); // riders can unlock again
    }
}

void depart() {
    sem_init(&bus_capacity, 0, 50);
}

void take_bus(void *arg) {

    pthread_mutex_lock(&has_arrived);   
    
    //  bus not yet arrived
    sem_post(&riders_waiting);

    pthread_mutex_unlock(&has_arrived);

    sem_wait(&bus_capacity);

}

int main() {

    //  random in [70, 150]
    // int n_riders = rand() % (150 - 70 + 1) + 70;
    int n_rider = 170;

    sem_init(&riders_waiting, 0, 0);    //  Nobody is waiting
    




    return 0;
}