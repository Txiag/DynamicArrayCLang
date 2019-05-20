#include <stdio.h>
#include <time.h>
#include "array_list_int.h"
/* calcula o tempo corrido em nanosegundos */
unsigned long long dif_time(struct timespec begin, struct timespec end){
  struct timespec dif;
  if (end.tv_nsec<=begin.tv_nsec){
    end.tv_nsec+=1000000000;
    end.tv_sec-=1;
  }
  dif.tv_sec = end.tv_sec - begin.tv_sec;
  dif.tv_nsec = end.tv_nsec - begin.tv_nsec;
  return dif.tv_sec*1000000000 + dif.tv_nsec;
}

int main(){
  int i;
  array_list_int a1 = ali_create();
  struct timespec begin,end;

  clock_gettime(CLOCK_REALTIME, &begin);
  for (i=0 ; i<10000 ; ++i){
    ali_push_back(a1,i);
  }
  clock_gettime(CLOCK_REALTIME, &end);

  printf("Tempo para inserir: %lluns\n",dif_time(begin,end));
  ali_destroy(a1);
  return 0;
}
