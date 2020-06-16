#include "sort.h"

/**
 * shell_sort - function that sorts an array of
 * integers in ascending order using the Shell
 * sort algorithm, using the Knuth sequence
 * @array: array to sort
 * @size: size or array
 * Return: none
 */

void shell_sort(int *array, size_t size)
{
	size_t itval = 1;
	size_t iter = 0;
	int temp = 0, changes = 0;

	if (!array || size < 2)
		return;
	while ((itval * 3) + 1 < size)
		itval = (itval * 3) + 1;
	while (itval >= 1)
	{
		if (itval != 1)
		{
			for (iter = size - 1; iter >= itval; iter--)
			{
				if (array[iter] < array[iter - itval])
				{
					temp = array[iter];
					array[iter] = array[iter - itval];
					array[iter - itval] = temp;
				}
			}
		}
		else
		{
			for (iter = size - 1; iter > 0; iter--)
			{
				if (array[iter] < array[iter - 1])
				{ temp = array[iter];
					array[iter] = array[iter - 1];
					array[iter - 1] = temp;
					changes++; }
				if (iter == 1 && changes != 0)
				{ changes = 0;
					iter = size; }
			}
		}
		iter = 0;
		itval = (itval - 1) / 3;
		print_array(array, size);
	}
}
