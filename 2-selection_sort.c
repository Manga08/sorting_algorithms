#include "sort.h"
/**
 * selection_sort - Sorts an array of integers with the Selection sort.
 * @array: The array.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	unsigned int ct1, ct2, crnt, temp;

	for (ct1 = 0; ct1 < size - 1; ct1++)
	{
		crnt = ct1;
		for (ct2 = ct1 + 1; ct2 < size; ct2++)
		{
			if (array[ct2] < array[ct1] && array[ct2] < array[crnt])
				crnt = ct2;
		}
		if (crnt != ct1)
		{
			temp = array[ct1];
			array[ct1] = array[crnt];
			array[crnt] = temp;
			print_array(array, size);
		}
	}
}
