#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid1 == 0) {
        while (1) {
            printf("b");
            fflush(stdout);
            sleep(1);
        }
    } else {
        pid2 = fork();

        if (pid2 < 0) {
            perror("fork failed");
            exit(1);
        } else if (pid2 == 0) {
            while (1) {
                printf("c");
                fflush(stdout);
                sleep(1);
            }
        } else {
            while (1) {
                printf("a");
                fflush(stdout);
                sleep(1);
            }
        }
    }

    return 0;
}