#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* func1(void* p) {
   printf("From the thread function1\n");
//   sleep(1);
   pthread_exit(NULL);
//   return NULL;
}

int main() {
   pthread_t t1,t2; // declare thread
   pthread_create(&t1, NULL, func1, NULL);
//   pthread_join(t1,NULL);
   sleep(1);
   printf("From the main function %d\n", t1);
}
