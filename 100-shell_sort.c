#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using a shell
 * sort algorithm, with gap sizes determined by a decreasing Knuth sequence
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void shell_sort(int *array, size_t size)
{
	int n = (int)size;
	int gap, i, j, temp, Knuth_max;

	if (!array || size < 2)
		return;

    /* Determine the initial gap size using Knuth sequence */
	for (gap = 1; gap < n; gap = (gap * 3) + 1)
	{
		/* Keep track of the maximum gap size */
		Knuth_max = gap;
	}

	/* Start with the largest Knuth sequence value less than n as the gap, */
	/* and work down the sequence to a gap of 1 */
	for (gap = Knuth_max; gap > 0; gap = (gap - 1) / 3)
	{
		/* Do a gapped insertion sort for this gap size */
		for (i = gap; i < n; i++)
		{
			/* Save array[i] in temp in preparation to overwrite */
			temp = array[i];

			/* Shift earlier gap-sorted elements up until the correct location */
			/* for array[i] is found */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			/* Move temp (original array[i]) to its correct location */
			array[j] = temp;
		}

		/* Print the array after each gap iteration */
		print_array(array, size);
	}
}
