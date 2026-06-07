#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int global_int = 0; 
 
void *job(void * arg){ 
  int local_int; 
  local_int = global_int;
  printf("Global is %d",local_int); 
  global_int = local_int + 1; 
  return NULL; 
} 
 
int main(){ 
  pthread_t threads[4]; 
  for(int i = 0; i < 4; i++){ 
    printf("ciao\n");
    if (pthread_create(&threads[i], NULL, job, NULL) != 0){
        exit(EXIT_FAILURE); 
        printf("Ciao");
    }
  }
  for (int i = 0;i<4;i++){
    pthread_join(threads[i],NULL);
  }
  printf("ok"); 
  return 0; 
}