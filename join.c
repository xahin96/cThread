#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//Passing a pointer to the thread function
void *func(void *p) {
    char *from_main;
    from_main = p;
    printf("From the thread function func %s\n", from_main);
    sleep(1);
    char *p1 = "\nReturned successfuly from Section 4 ";
    pthread_exit(p1);
}

int main() {
    pthread_t t1; // declare thread
    void *ret;
    char *haha = "haha";
    pthread_create(&t1, NULL, func, haha);
    pthread_join(t1, &ret);
    printf("The return value fromm the thread is \n %s", ret);
}
