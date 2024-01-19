#include "sort.h"

/**
 * partition - partitions the array using the Lomuto partition scheme
 * @array: array of integers to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: number of elements in the array
 * Return: new index at which to start a new recursive partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i);
}

/**
 * quicksort - recursively sorts the array using the Lomuto quicksort
 * @array: array of integers to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: number of elements in the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		quicksort(array, low, p - 1, size);
		quicksort(array, p + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using quicksort
 * @array: array of integers to be sorted
 * @size: number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, (int)size - 1, size);
}
