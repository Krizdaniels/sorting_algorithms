#include "sort.h"
/**
*swap - Positions of two elements into an array
*@array: array
*@item1: The array element
*@item2: The array element
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 *hoare_partition - The hoare partition sorting scheme implementation
 *@array: array
 *@first: The first array element
 *@last: The last array element
 *@size: The size array
 *Return: Position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{

		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		swap(array, current, finder);
		print_array(array, size);
	}
}
/**
 *qs - The qucksort algorithm implementation
 *@array: array
 *@first: The first array element
 *@last: The last array element
 *@size: The array size
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		qs(array, first, position - 1, size);
		qs(array, position, last, size);
	}
}
/**
 *quick_sort_hoare - To prepare the terrain to quicksort algorithm
 *@array: The array
 *@size: The array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
