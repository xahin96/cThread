#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *func(void *p) {

    printf("Message from the thread with thread id=%d\n", pthread_self());
    sleep(1);
    pthread_exit(NULL);
    return NULL;
}

int main() {
    pthread_t t1, t2, t3, t4; // declare thread

    pthread_create(&t1, NULL, func, NULL);
    printf("\nFrom the main function with thread id %d\n", t1);
    pthread_create(&t2, NULL, func, NULL);
    printf("\nFrom the main function with thread id %d\n", t2);
    pthread_create(&t3, NULL, func, NULL);
    printf("\nFrom the main function with thread id %d\n", t3);
    pthread_create(&t4, NULL, func, NULL);
    printf("\nFrom the main function with thread id %d\n", t4);
    sleep(2);
    printf("\nFrom the main function with thread id %d\n", pthread_self());
}
