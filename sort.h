#ifndef SORT_H
#define SORT_H
#include <stddef.h>

/**
 * enum bool_e - manual definition of booleans, in case C99 stdbool.h not
 * available
 * @false: logical 0
 * @true: logical 1
 */
typedef enum bool_e
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
int partition(int *array, int low, int high, size_t size);
void quicksort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void dll_adj_swap(listint_t **list, listint_t *left, listint_t *right);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void PrintArray(int *array, int iBeg, int iEnd);
void CopyArray(int *source, int iBeg, int iEnd, int *dest);
void TopDownMerge(int *source, int iBeg, int iMid, int iEnd, int *dest);
void TopDownSplitMerge(int *source, int iBeg, int iEnd, int *dest);
void merge_sort(int *array, size_t size);
int ParentIndex(int i);
int LeftChildIndex(int i);
void heapify(int *array, size_t size, int start, int end);
void heap_sort(int *array, size_t size);
void init_bucket_count(int *bucket_count);
int **build_buckets(int *bucket_count);
int find_max(int *array, size_t size);
void into_array(int *array, size_t size, int **buckets, int *bucket_count);
void radix_sort(int *array, size_t size);
/*void bitonic_compare(bool up, int *x, size_t size);
void bitonic_merge(bool up, int *x, size_t size, size_t orig_size);
void bitonic_sort_r(bool up, int *x, size_t size, size_t orig_size);*/
void bitonic_sort(int *array, size_t size);
int hoare_partition(int *array, size_t low, size_t high, size_t size);
void hoare_quicksort_recursive(int *array, size_t low, size_t high, size_t size);
void quick_sort_hoare(int *array, size_t size);
int _strcmp(const char *str1, const char *str2);

#endif
