#include "sem.h"

int buffer[SIZE];
sem_t mutex, full, empty;

void removeFirstElement(int *arr, int size) {
    if (size > 0) {
        for (int i = 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }
    }
}

void printBuffer(int* buf, int size) {
    printf("buffer: [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", buf[i]);
    }
    printf("]\n");
}

void* destroyAll() {
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return NULL;
}

void* initAll() {
    initSem(&mutex, 1);
    initSem(&empty, SIZE);
    initSem(&full, 0);
    memset(buffer, 0, SIZE * sizeof(int));
    return NULL;
}

void* initSem(sem_t* sem, int val) {
    if(sem_init(sem, 0, val) < 0) {
        perror("sem_init");
        exit(EXIT_FAILURE);
    }
    return NULL;
}

void* P(sem_t* sem) {
    sem_wait(sem);
    return NULL;
}

void* V(sem_t* sem) {
    sem_post(sem);
    return NULL;
}