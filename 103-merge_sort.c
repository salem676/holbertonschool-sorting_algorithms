#include "sort.h"
/**
 * merge - merges l and r arrays into original array.
 * Description: as above.
 * @array: pointer to array.
 * @size: size of the array.
 * @l: pointer to left array.
 * @r: pointer to right array.
 **/
void merge(int *array, int *l, int *r, size_t size)
{
	int i = 0, j = 0, k = 0;
	int size_l, size_r;
	/*
	 * @i: counter.
	 * @j: counter.
	 * @k: counter.
	 * @size_l: int size.
	 * @size_r: int size
	 */
	size_l = size / 2;
	size_r = size - size_l;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, size_l);
	printf("[right]: ");
	print_array(r, size_r);
	while (i < size_l && j < size_r)
	{
		if (l[i] < r[j])
			array[k++] = l[i++];
		else
			array[k++] = r[j++];
	}
	while (i < size_l)
		array[k++] = l[i++];
	while (j < size_r)
		array[k++] = r[j++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - sorts an array of integers in ascending order using
 * the Merge sort algorithm.
 * Description: as above.
 * @array: pointer to array.
 * @size: size of the array.
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid = 0, i;
	int left[1000];
	int right[1000];
	/*
	 * @mid: init in zero size_t.
	 * @i: size_t var.
	 * @left: int array size 1000.
	 * @right: int array size 1000.
	 */
	if (!array)
		return;
	if (size < 2)
		return;
	mid = size / 2;
	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, size);
}
