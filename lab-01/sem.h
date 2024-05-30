#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

#define SIZE 10

extern int buffer[];

extern sem_t mutex, full, empty;

void removeFirstElement(int *arr, int size);
void printBuffer(int* buf, int size);
void* destroyAll();
void* initAll();
void* initSem(sem_t* sem, int val);
void* P(sem_t* sem);
void* V(sem_t* sem);