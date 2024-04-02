#include <pthread.h>
#include <stdio.h>

void* thread_function(void* arg) {
    printf("Inside thread_function\n");
    return NULL;
}

void* another_function(void* arg) {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_function, NULL);

    printf("Inside another_function\n");

    pthread_join(thread_id, NULL); // Wait for the new thread to finish

    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, another_function, NULL);

    printf("Inside main\n");

    pthread_join(thread_id, NULL); // Wait for the thread created by main to finish

    return 0;
}
