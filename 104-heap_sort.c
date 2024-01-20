#include "sort.h"

/**
 * ParentIndex - returns index of parent node for an array arranged as a binary
 * tree, for index i
 * @i: current index
 * Return: index of parent node
 */
int ParentIndex(int i)
{
	return ((i - 1) / 2);
}

/**
 * LeftChildIndex - returns index of left child branch for an array arranged as
 * a binary tree, for index i
 * @i: current index
 * Return: index of left child node
 */
int LeftChildIndex(int i)
{
	return ((2 * i) + 1);
}

/**
 * heapify - converts an array to a heap
 * @array: array of integers
 * @size: number of elements in array
 * @start: starting index
 * @end: ending index
 */
void heapify(int *array, size_t size, int start, int end)
{
	int root, largest, temp, child;

	root = start;

	while (LeftChildIndex(root) <= end)
	{
		child = LeftChildIndex(root);
		largest = root;

		if (array[largest] < array[child])
			largest = child;

		if (child + 1 <= end && array[largest] < array[child + 1])
			largest = child + 1;

		if (largest != root)
		{
			temp = array[root];
			array[root] = array[largest];
			array[largest] = temp;
			print_array(array, size);
			root = largest;
		}
		else
		{
			return;
		}
	}
}

/**
 * heap_sort - sorts array of integers in ascending order using heap sort
 * @array: array of values to be sorted
 * @size: number of elements in array
 */
void heap_sort(int *array, size_t size)
{
	int start, end, temp;

	if (!array || size < 2)
		return;

	/* Convert array to a max heap */
	end = (int)size - 1;
	start = ParentIndex(end);

	while (start >= 0)
	{
		heapify(array, size, start, end);
		start--;
	}

	/* Extract elements from the heap one by one */
	while (end > 0)
	{
		/* Swap the root (maximum value) with the last element of the heap */
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);

		/* Reduce the size of the heap and heapify the root */
		end--;
		heapify(array, size, 0, end);
	}
}
