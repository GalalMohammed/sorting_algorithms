#include "sort.h"

/**
 * shell_sort - sorts array of ints (ascending) using the Shell sort,
 * using Knuth sequence
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array)
	{
		while (gap * 3 + 1 < size)
			gap = gap * 3 + 1;
		/**
		 * Start with the largest gap and work down to a gap of 1
		 * similar to insertion sort but instead of 1,
		 * gap is being used in each step
		 */
		while (gap)
		{
			/* Each loop leaves array[0:gap-1] in gapped order */
			for (i = gap; i < size; i++)
			{
				/**
				 * save array[i] in temp and make a hole at position i
				 */
				temp = array[i];
				/**
				 * shift earlier gap-sorted elements
				 * up until the correct location
				 * for array[i] is found
				 */
				for (j = i; j >= gap
						&& array[j - gap] > temp;
						j -= gap)
					array[j] = array[j - gap];
				/**
				 * put temp (the original array[i])
				 * in its correct location
				 */
				array[j] = temp;
			}
			print_array(array, size);
			gap = (gap - 1) / 3;
		}
	}
}
