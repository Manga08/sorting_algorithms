#include "sort.h"

/**
 * counting_sort - Function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: none
 */

void counting_sort(int *array, size_t size)
{
	size_t max = 0, i = 0, j = 0, counter = 0;
	int *auxar = NULL, *finalarr = NULL, ax = 0;

	if (!array || size < 2)
		return;
	for (; i < size; i++)
	{
		for (; j < size; j++)
		{
			if (array[j] > array[i])
				max = array[j], i = j;
		}
	}
	auxar = calloc(max + 1, sizeof(int));
	if (!auxar)
		return;
	for (i = 0; i < max + 1; i++)
	{
		ax = i;
		for (j = 0; j < size; j++)
		{
			if (ax == array[j])
				counter++;
		}
		auxar[i] = counter;
		counter = 0, j = 0;
	}
	for (i = 1; i < max + 1; i++)
		auxar[i] = auxar[i] + auxar[i - 1];

	finalarr = malloc(sizeof(int) * size);
	if (!finalarr)
		return;
	print_array(auxar, max + 1);
	for (i = 0; i < size; i++)
		finalarr[auxar[array[i] - 1]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = finalarr[i];
	free(auxar);
	free(finalarr);
}
