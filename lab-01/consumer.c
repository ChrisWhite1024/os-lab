#include "obj.h"

void* consumer() {
    while(1) {

        srand(time(0));
        int randomTime = rand() % 10 + 1;

        P(&full);
        P(&mutex);
        removeFirstElement(buffer, SIZE);
        printf("\033[0;32mconsumer:\033[0m remove %d\n", buffer[0]);
        printBuffer(buffer, SIZE);
        printf("\n");
        V(&mutex);
        V(&empty);

        sleep(randomTime);
    }
}