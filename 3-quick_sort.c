#include "sort.h"

/**
 * partition - implements the partition step of the quicksort algorithm
 * @array: array to be sorted
 * @low: first position of the subarray to be partitioned
 * @high: last position of the subarray to be partitioned
 * @size: size if the array
 *
 * Return: position of the last element sorted
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j, tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (array[i] != array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		tmp = array[i];
		array[i] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_helper - implements quicksort algorithm using recurion
 * @array: array to be sorted
 * @low: first position of the subarray to be partitioned
 * @high: last position of the subarray to be partitioned
 * @size: size if the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		quick_sort_helper(array, low, p - 1, size);
		quick_sort_helper(array, p + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size if array
 */
void quick_sort(int *array, size_t size)
{
	if (array)
		quick_sort_helper(array, 0, size - 1, size);
}
