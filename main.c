#include <stdio.h>
#include "array_list_int.h"
#include <time.h>

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
  printf("\n--------------------------------------\n\n");
  int contTestes, i,t, elementos = contTestes+1, aux;
  for (contTestes = 0; contTestes < 5; contTestes++){
    elementos*=50;
    i = 0;
    t = 0;
    printf("Criando array nº %d", contTestes+1);
    for (i = 0; i < 3; i++){
      printf(".");
      //sleep(2)
    }
    printf("\n");
    array_list_int array1 = ali_create();
    struct timespec begin,end;

    // Push Back
    clock_gettime(CLOCK_REALTIME, &begin);
    printf("Preenchendo array com %d elementos\n", elementos);
    for (i=0; i < elementos ; ++i)
      ali_push_back(array1,i*3+1);
    clock_gettime(CLOCK_REALTIME, &end);
    t = ali_size(array1);

    printf("\n--------------------------------------\n\n")
; 
    printf("Tempo para push_back: %0.3fms\n",(double)dif_time(begin,end)/1000000);
    printf("Tamanho de a1: %d\nPorcentagem ocupada: %f\n",t, ali_percent_occuped(array1));
    //Fim Push Back

    //Pop Back
    clock_gettime(CLOCK_REALTIME, &begin);
    ali_pop_back(array1);
    ali_pop_back(array1);
    ali_pop_back(array1);
    ali_pop_back(array1);
    ali_pop_back(array1);
    ali_pop_back(array1);
    ali_pop_back(array1);
    ali_pop_back(array1);
    ali_pop_back(array1);
    ali_pop_back(array1);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("\n\n");  
    t = ali_size(array1);

    printf("Tempo para 10 pop_back: %0.3fms\n",(double)dif_time(begin,end)/1000000);

    printf("Tamanho de a1: %d\nPorcentagem ocupada: %lf\n",t, ali_percent_occuped(array1));
    printf("\n\n");   
    //Fim Pop Back

    printf("Repreenchendo o array...\n");
    for (i = elementos-10; i < elementos; i++)
    ali_push_back(array1,i*3+1);

    // Get
    clock_gettime(CLOCK_REALTIME, &begin);
    ali_get(array1, ali_size(array1)-1);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("\n\n");  


    
    printf("Tempo para ali_get - Ultimo Index: %0.3fms\n",(double)dif_time(begin,end)/1000000);
    //Fim Get

    //Find
      printf("\n\n");  
    t = ali_size(array1);
    aux = ali_get(array1, i-1);
    clock_gettime(CLOCK_REALTIME, &begin);
    ali_find(array1, aux);
    clock_gettime(CLOCK_REALTIME, &end);  

    printf("Tempo para achar ultimo elemento: %0.3fms\n",(double)dif_time(begin,end)/1000000);
    printf("\n\n");   
    //Fim Find

    //InsertAt
    clock_gettime(CLOCK_REALTIME, &begin);
    ali_insert_at(array1, 0, 2);
    clock_gettime(CLOCK_REALTIME, &end);  
    t = ali_size(array1);
    printf("Tempo para inserir no primeiro indice: %0.3fms\n",(double)dif_time(begin,end)/1000000);
    printf("Tamanho de a1: %d\nPorcentagem ocupada: %lf\n",t, ali_percent_occuped(array1));
    printf("\n\n");  
    //Fim InserAt
    //Remove From
    clock_gettime(CLOCK_REALTIME, &begin);
    ali_remove_from(array1, 0);
    clock_gettime(CLOCK_REALTIME, &end);  
    t = ali_size(array1);
    printf("Tempo para remover do primeiro indice: %0.3fms\n",(double)dif_time(begin,end)/1000000);
    printf("Tamanho de a1: %d\nPorcentagem ocupada: %lf\n",t, ali_percent_occuped(array1));
    printf("\n\n"); 
    //Fim RemoveFrom
    printf("Apagando Array nº %d...\n\n", contTestes+1);
    ali_destroy(array1);
    
    printf("--------------------------------------\n\n")
; 
  }
  return 0;
}
