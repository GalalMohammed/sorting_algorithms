#include "sort.h"

/**
 * merge - sorts subarrays
 * @array: array to be sorted
 * @low: first position of the subarray
 * @mid: middle position of the subarray
 * @high: last position of the subarray
 * @temp: store the sorted subarray
 */
void merge(int *array, int low, int mid, int high, int *temp)
{
	int i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + low, mid - low);
	printf("[right]: ");
	print_array(array + mid, high - mid);
	i = low;
	j = mid;
	k = low;

	while (k < high)
	{
		if (i < mid && (j >= high || array[i] <= array[j]))
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
		k++;
	}
	for (i = low; i < high; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array + low, high - low);
}

/**
 * merge_sort_helper - implement merge sort using recursion
 * @array: array to be sorted
 * @low: first position of the subarray
 * @high: last position of the subarray
 * @temp: store the sorted subarray
 */
void merge_sort_helper(int *array, int low, int high, int *temp)
{
	int mid;

	if (high - low > 1)
	{
		mid = (high + low) / 2;
		merge_sort_helper(array, low, mid, temp);
		merge_sort_helper(array, mid, high, temp);
		merge(array, low, mid, high, temp);
	}
}
/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array to be sorted
 * @size: size if array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	merge_sort_helper(array, 0, size, temp);
	free(temp);
}
