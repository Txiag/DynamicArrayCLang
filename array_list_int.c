/**
 * ANSI C Array List of int values library
 *
 * Implementation file
 *
 * Author: Thiago do Nascimento Ferreira
 * Date: 20/05/2019
 *
 */


#include "array_list_int.h"
#include <stdio.h>
#include <stdlib.h> /* For malloc and free */

#define MAGIC 314159265

struct array_list_int{
  int *a;
  int size;
  int capacity;
  int magic;
};

/* Internal functions */

/* Check if the pointer actually points to a valid array_list_int struc */
int ali_check_type(array_list_int ali){
  if (ali->magic!=MAGIC){
    return 0;
  } else {
    return 1;
  }
}

/* Increase capacity size of the array_list_int internal storage */
int ali_realloc(array_list_int ali){
  int* tmp = (int *) realloc(ali->a, (ali->size + 1)*sizeof(int));
  if (tmp != NULL){
    ali->a = tmp;
    ali->capacity++;
    return ali->capacity;
  }
  return 0; /* Realloc could not allocate new memory */
  
}


/* External (public) functions.
 * + Defined in array_list_int.h file
 */

/* creates new instance of a dynamic array */
array_list_int ali_create(){
  array_list_int ali= (array_list_int)malloc(sizeof(struct array_list_int));
  ali->a = (int*)malloc(sizeof(int)*4);
  ali->size=0;
  ali->capacity=4;
  ali->magic=MAGIC;
  return ali;
}

/* Get the value at index 'index' */
int ali_get(array_list_int ali, int index){
  if (!ali_check_type(ali))
    return 0;
  if (index<0 || index>=ali->size){
    return 0;
  }
  return ali->a[index];
}

/* Adds value 'value' to the end of the dynamic array */
unsigned int ali_push_back(array_list_int ali, int value){
  if (!ali_check_type(ali))
    return 0;
  if (ali->size == ali->capacity)
    if (ali_realloc(ali) == 0)
      return -1;
  ali->a[ali->size++]=value;
  return ali->size;
}

/* Removes last value of dynamic array 'ali'
 *
 */
unsigned int ali_pop_back(array_list_int ali){
  if (!ali_check_type(ali))
    return 0;
if (ali->size == 0)
    return 0;
  ali->size--;
  return ali->size;
}


/* Gets number of int elements stored in 'ali' */
unsigned int ali_size(array_list_int ali){
  if (!ali_check_type(ali))
    return 0;
  return ali->size;
}


int ali_find(array_list_int ali, int value){
  int i = 0;
  for (i=0; i<ali->size; i++){
    if (ali->a[i] == value){
      return i;
    }
  }
  return -1;
}

int ali_insert_at(array_list_int ali, int index, int value){
  int i;
  if (!ali_check_type(ali))
    return 0;
  if (ali->size == ali->capacity)
    if (!ali_realloc(ali))
      return 0;
  ali->size++;
  for (i = (ali->size)-1; i > index; i--){
    ali->a[i] = ali->a[i-1];
  }
  ali->a[index] = value; 
  return index;
}

int ali_remove_from(array_list_int ali, int index){
  if (index < 0 || index >= ali->size) return -1;
  int i;
  for (i = index; i < ali->size-1; i++){
    ali->a[i] = ali->a[i+1];
  }
  ali->size--;
  return ali->size;
}

unsigned int ali_capacity(array_list_int ali){
  return ali->capacity;
}

double ali_percent_occuped(array_list_int ali){
  return (ali->size / ali->capacity);
}
/* Release memory used by the struct and invalidate it. */
void ali_destroy(array_list_int ali){
  free(ali->a);
  ali->size=0;
  ali->capacity=0;
  ali->magic=0;
}
