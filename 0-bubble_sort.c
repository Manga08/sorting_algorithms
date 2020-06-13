#include "sort.h"
/**
 * bubble_sort -  sorts an array of integers in ascending order by Bubble sort.
 * @array: pointer to array
 * @size: size
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int ct, ct2, temp;

	if (array == NULL || size < 2)
		return;

	for (ct = 0; ct < size - 1; ct++)
	{
		for (ct2 = 0; ct2 < size - 1 - ct; ct2++)
		{
			if (array[ct2] > array[ct2 + 1])
			{
				temp = array[ct2];
				array[ct2] = array[ct2 + 1];
				array[ct2 + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
