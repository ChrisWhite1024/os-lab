#include "obj.h"

void* consumer() {
    while(1) {

        srand(time(0));
        int randomTime = rand() % 10 + 1;

        P(&full);
        P(&mutex);
        printf("\033[0;32mconsumer:\033[0m remove %d\n", buffer[0]);
        removeFirstElement(buffer, SIZE);
        V(&mutex);
        V(&empty);

        printBuffer(buffer, SIZE);
        printf("\n");
        sleep(randomTime);
    }
}