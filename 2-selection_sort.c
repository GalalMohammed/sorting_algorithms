#include "sort.h"

/**
 * selection_sort - sorts array of ints (ascending) using Selection sort.
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	/* array[0] to array[size - 1] is the array to sort */
	size_t i, j;
	int tmp;

	if (array)
		/* advance the position through the entire array */
		/**
		 * could do i < size - 1
		 * as single element is also min element
		 */
		for (i = 0; i < size - 1; i++)
		{
			/* find min element in array[i:size-1] */
			/* assume min is the first element */
			size_t jmin = i;
			/**
			 * test against elements after
			 * i to find the smallest
			 */
			for (j = i + 1; j < size; j++)
				/**
				 * if this element is less,
				 * then it is the new minimum
				 */
				if (array[j] < array[jmin])
					/**
					 * found new minimum;
					 * remember its index
					 */
					jmin = j;
			if (jmin != i)
			{
				tmp = array[i] ^ array[jmin];
				array[i] ^= tmp;
				array[jmin] ^= tmp;
				print_array(array, size);
			}
		}
}
