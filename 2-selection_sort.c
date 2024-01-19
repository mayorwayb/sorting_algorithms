#include "sort.h"

/**
 * selection_sort - sorts an array of integers using a selection sort algorithm
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (!array || size < 2)
		return;

	/* at every position in the n-member array */
	for (i = 0; i < size - 1; i++)
	{
		/* assume the current index is the minimum */
		min_idx = i;

		/* scan from that position to the end, */
		for (j = i + 1; j < size; j++)
		{
			/* determine the minimum value in that range */
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}

		/* and if it is lower than the value at the start of the range, */
		/* swap them */
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
