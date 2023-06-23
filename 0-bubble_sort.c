#include "sort.h"

/**
 * bubble_sort - sorts array of ints (ascending) using Bubble sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n = size;
	int tmp;
	char swapped;

	if (array)
		do {
			swapped = 0;
			for (i = 1; i < n; i++)
				if (array[i - 1] > array[i])
				{
					tmp = array[i - 1] ^ array[i];
					array[i - 1] ^= tmp;
					array[i] ^= tmp;
					swapped = 1;
					print_array(array, size);
				}
			n -= 1;
		} while (swapped);
}
