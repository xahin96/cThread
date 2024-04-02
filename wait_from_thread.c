#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_t g_thread_id;

void *thread_function(void *arg) {
    g_thread_id = pthread_self();
    for (int i = 0; i < 3; i++) {
        printf("%d\n", i);
        sleep(1);
    }
    return NULL;
}

void *another_function(void *arg) {
    sleep(1);
    pthread_t thread_id;
//    pthread_create(&thread_id, NULL, thread_function, NULL);

    printf("Inside another_function\n");

    pthread_join(g_thread_id, NULL); // Wait for the new thread to finish

    return NULL;
}

int main() {
    pthread_t thread_id_1, thread_id_2;
    pthread_create(&thread_id_1, NULL, another_function, NULL);
    pthread_create(&thread_id_2, NULL, thread_function, NULL);
    printf("Inside main\n");

//    pthread_join(thread_id, NULL); // Wait for the new thread to finish


    pthread_join(thread_id_1, NULL); // Wait for the thread created by main to finish

    return 0;
}
