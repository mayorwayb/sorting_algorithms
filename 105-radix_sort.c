#include "sort.h"
#include <stdlib.h>

/**
 * init_bucket_count - resets bucket_count values to 0
 * @bucket_count: array containing amounts of members for arrays in `buckets`
 */
void init_bucket_count(int *bucket_count)
{
	for (int i = 0; i < 10; i++)
		bucket_count[i] = 0;
}

/**
 * build_buckets - allocates space for arrays to be held in `buckets`
 * @buckets: array of arrays each containing sorted members of `array`
 * @bucket_count: array containing amounts of members for arrays in `buckets`
 */
int **build_buckets(int *bucket_count)
{
	int **buckets = malloc(sizeof(int *) * 10);
	if (!buckets)

		exit(EXIT_FAILURE);

	for (int i = 0; i < 10; i++)
	{
		buckets[i] = malloc(sizeof(int) * bucket_count[i]);
		if (!buckets[i])
		{
			for (; i >= 0; i--)
				free(buckets[i]);
			free(buckets);
			exit(EXIT_FAILURE);
		}
	}
	init_bucket_count(bucket_count);
	return (buckets);
}

/**
 * find_max - searches array of integers for the highest value
 * @array: array of values to be searched
 * @size: number of elements in array
 * Return: largest integer stored in array
 */
int find_max(int *array, size_t size)
{
	int max = array[0];
	for (size_t i = 1; i < size; i++)

		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * into_array - flattens buckets into an array sorted by current digit place,
 * then prints results and frees current buckets for the next pass
 * @array: array of values to be printed
 * @size: number of elements in array
 * @buckets: array of arrays each containing sorted members of `array`
 * @bucket_count: array containing amounts of members for arrays in `buckets`
 */
void into_array(int *array, size_t size, int **buckets, int *bucket_count)
{
	int i, j, k;

	/* flatten bucket members in order into array sorted by place */
	for (k = 0, i = 0; k < 10; k++)
	{
		for (j = 0; j < bucket_count[k]; j++, i++)
			array[i] = buckets[k][j];
	}
	/* print results */
	print_array(array, size);
	/* free buckets from the current pass */
	for (i = 0; i < 10; i++)
		free(buckets[i]);
}

/**
 * radix_sort - Sorts array of integers in ascending order using a Radix sort
 * algorithm starting with the LSD, the 'least significant (1s place) digit',
 * and sorting by the next digit to the left. The size of `bucket_count` here is
 * determined by the max range of key variance (digits 0-9). Other solutions may
 * be needed for much larger ranges.
 * @array: array of values to be sorted
 * @size: number of elements in array
 */
void radix_sort(int *array, size_t size)
{
	int **buckets;
	int bucket_count[10];
	int max, max_digits, pass, divisor, digit;

	if (!array || size < 2)
		return;

	/* Find the amount of places in the largest element */
	max = find_max(array, size);
	for (max_digits = 0; max > 0; max_digits++)
		max /= 10;

	/* One sorting pass for each place in max_digits */
	for (pass = 0, divisor = 1; pass < max_digits; pass++, divisor *= 10)
	{
		init_bucket_count(bucket_count);

		/* Find the amount of members in each bucket */
		for (size_t i = 0; i < size; i++)
		{
			digit = (array[i] / divisor) % 10;
			bucket_count[digit]++;
		}

		buckets = build_buckets(bucket_count);

		/* Fill buckets sorting by digit at the current power of 10 */
		for (size_t i = 0; i < size; i++)
		{
			/* Find the digit of the source element at that power of 10 */
			digit = (array[i] / divisor) % 10;
			/* Place the member of the source array in the digit's bucket */
			buckets[digit][bucket_count[digit]] = array[i];
			/* Record an increase in the bucket fill level */
			bucket_count[digit]++;
		}

		into_array(array, size, buckets, bucket_count);
	}

	free(buckets);
}

