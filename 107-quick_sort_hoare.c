#include "sort.h"
#include <stdbool.h>
#include <stdio.h>

/**
 * hoare_partition - Hoare partition scheme using rightmost index as pivot
 * @array: array of integers to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 * Return: new index for recursive partitioning
 */
int hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot, temp;
	size_t i, j;

	pivot = array[high];
	i = low - 1;
	j = high + 1;

	while (true)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i == j)
			return (j - 1);
		else if (i > j)
			return (j);

		/* Swap elements */
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;

		/* Print array for visualization */
		print_array(array, size);
	}
}

/**
 * hoare_quicksort_recursive - recursive function for Hoare quicksort
 * @array: array of integers to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 */
void hoare_quicksort_recursive(int *array, size_t low, size_t high, size_t size)
{
	size_t partition_border;

	if (low < high)
	{
		partition_border = hoare_partition(array, low, high, size);
		hoare_quicksort_recursive(array, low, partition_border, size);
		hoare_quicksort_recursive(array, partition_border + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts array of integers in ascending order using a quick
 * sort, Hoare partition scheme algorithm
 * @array: array of values to be printed
 * @size: number of elements in array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_quicksort_recursive(array, 0, size - 1, size);
}
