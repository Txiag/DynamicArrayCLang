/**
 * ANSI C Array List of int values library
 *
 * Author: Thiago do Nascimento Ferreira
 * Date: 20/05/2019
 *
 */

#ifndef _ARRAY_LIST_INT_H_
#define _ARRAY_LIST_INT_H_

/**
 * Type: array_list_int
 * Description: an array_list_int is a pointer to a type that
 *              stores the dynamic array data. The struct is
 *              defined in the array_list_int implementation.
 *
 */
typedef struct array_list_int * array_list_int;

/**
 * Function: array_list_int ali_init();
 *
 * Description: Creates and initialize a dynamic array list of integers.
 *
 * Return: The array_list_int type, a reference (pointer)
 *         to a dynamic array implementation
 *
 */
array_list_int ali_create();

/**
 * Function: int ali_get(array_list_int ali, int index);
 *
 * Description: Gets the element at index 'index'.
 *
 * Return: The element located at index i.
 *         The value is undeterminated if index is not in the range [0..size-1]
 *
 */
int ali_get(array_list_int ali, int index);

/**
 * Function: unsigned int ali_push_back(array_list_int ali, int i);
 *
 * Description: Add integer value 'i' to the end of the 'ali' dynamic array.
 *
 * Return: The number of elements stored in 'ali' AFTER inserting 'i'.
 *
 */
unsigned int ali_push_back(array_list_int ali, int i);

/**
 * Function: unsigned int ali_pop_back(array_list_int ali);
 *
 * Description: Removes the last element of the dynamic array
 *              referenced (pointed) by 'ali.
 *
 * Return: The number of elements after deletion. -1 if the array
 *         was empty before deletion.
 *
 */
unsigned int ali_pop_back(array_list_int ali);


/**
 * Function: unsigned int ali_size(array_list_int ali);
 *
 * Description: Computes the number of int elements stored in 'ali'.
 *
 * Return: The number of integer values stored in 'ali'.
 *
 */
unsigned int ali_size(array_list_int ali);

/**
 * Function: int ali_find(array_list_int ali, int element);
 *
 * Description: Gets the index of  element 'element'.
 *
 * Return: The index of element 'element' if element is in the range [0..size-1].
 *
 */
int ali_find(array_list_int ali, int element);

/**
 * Function: int ali_insert_at(array_list_int ali, int index, int value);
 *
 * Description: Inserts int value 'value' at index 'index'. 'index' must
 *              be a valid index, between 0 and 'ali_size'-1.
 *
 * Return: the value index, if insertion ok or -1 if the insertion could
 *         not be done.
 *
 */
int ali_insert_at(array_list_int ali, int index, int value);

/**
 * Function: ali_remove_from(array_list_int ali, int index);
 *
 * Description: Removes the value at index 'index'. 'index' must
 *              be a valid index, between 0 and 'ali_size'-1.
 *
 * Return: The size of the new array_list_int.
 *
 */
int ali_remove_from(array_list_int ali, int index);

/**
 * Function: unsigned int ali_capacity(array_list_int ali);
 *
 * Description: Computes the array_list_int ali capacity.
 *
 * Return: The capicity of the 'ali' array_list_int.
 *
 */
unsigned int ali_capacity(array_list_int ali);

/**
 * Function: double ali_percent_occuped(array_list_int ali);
 *
 * Description: Check the array_list_int 'ali' occupation, in percent.
 *
 * Return: A double, from 0 to 1 with the occupation rate of 'ali'.
 *
 */
double ali_percent_occuped(array_list_int ali);

/**
 * Function: void ali_destroy(array_list_int ali);
 *
 * Description: Relese memory used by the 'ali' reference.
 *              Invalidate memory area too.
 *
 */
void ali_destroy(array_list_int ali);

/**
 * Function: int ali_realloc(array_list_int ali);
 *
 * Description: Reallocate the array's capacity
 *
 * Return: the new capacity or 0 if realloc failed
 *
 */
int ali_realloc(array_list_int ali);
#endif
