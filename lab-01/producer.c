#include "obj.h"

void* producer() {
    int index;
    while(1) {
        srand(time(0));
        int randomNumber = rand();
        int randomTime = rand() % 10 + 1;
        
        P(&empty);
        P(&mutex);
        sem_getvalue(&full, &index);
        buffer[index] = randomNumber;
        printf("\033[0;31mproducer:\033[0m add %d\n", randomNumber);
        V(&mutex);
        V(&full);

        printBuffer(buffer, SIZE);
        printf("\n");
        sleep(randomTime);
    }
}

