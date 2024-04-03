#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[10];
int num = 10;
pthread_mutex_t lock; //Mutex step1 - GLobal Declaration

void *decrement(void *args) {
    int *detached = args;
    pthread_mutex_lock(&lock); //Mutex step3(within the thread) - Locking
    if (num >= 1) {
        if (*detached) {
        } else {
            num = num - 1;
            printf("num: %d, tid: %d\n", num, pthread_self());
        }
    } else {
        printf("Sorry,all tickets are booked\n");
    }

    pthread_mutex_unlock(&lock); //Mutex step4(withing the thread) -Unlocking
    return NULL;
}

int main(void) {
    int flick = 0;
    int detached = 1;
    int non_detached = 0;

    pthread_attr_t att;
    pthread_attr_init(&att);
    pthread_attr_setdetachstate(&att, PTHREAD_CREATE_DETACHED);

    if (pthread_mutex_init(&lock, NULL) != 0) //Mutex step2 - Initialization
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        if (flick) {
            pthread_create(&(tid[i]), &att, decrement, &detached);
            flick = 0;
        } else {
            pthread_create(&(tid[i]), NULL, decrement, &non_detached);
            pthread_join(tid[i], NULL);
            flick = 1;
        }
    }

    pthread_mutex_destroy(&lock); //Mutex step5 - Destroy
    pthread_attr_destroy(&att);

    printf("The main thread starts excution\n");
    return 0;
}