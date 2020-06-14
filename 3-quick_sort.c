#include "sort.h"
/**
 * sort - sort the array.
 * @array: The array.
 * @size: The size of the array.
 * @low: The lowest of the array.
 * @hight: the hightest of the array.
 * Return: The pivot.
 */
int sort(int *array, size_t size, int low, int hight)
{
	int pivot = array[hight], i, j = low, temp = 0;

	for (i = low; i < hight; i++)
		if (array[i] < pivot)
		{
			if (i != j && array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			j++;
		}
	if (hight != j && array[hight] != array[j])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
	return (j);
}
/**
 * partition - Part the array in 2.
 * @array: The array.
 * @size: The size of the array.
 * @low: The lowest of the array.
 * @hight: the hightest of the array.
 */
void partition(int *array, size_t size, int low, int hight)
{
	int pivot;

	if (low < hight)
	{
		pivot = sort(array, size, low,  hight);
		partition(array, size, low, pivot - 1);
		partition(array, size, pivot + 1, hight);
	}
}
/**
 * quick_sort - Sorts an array of integers with the Selection sort.
 * @array: The array.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	int hight = size - 1;

	if (size < 2)
		return;

	partition(array, size, 0, hight);
}
