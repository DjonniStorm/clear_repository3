#include <stdio.h>

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);
//образец (как сортировка выглядит) взял отсюда https://github.com/portfoliocourses/c-example-code/blob/main/merge_sort.c
int main()
{
	int array[10]; /*= { 9, 4, 8, 1, 7, 0, 3, 2, 5, 6, 10, 78, 0};*/
	int length = 10;
	for (int i = 0; i < 10; i++) {
		scanf_s("%d ", &array[i]);
	}
	merge_sort(array, length);
	for (int i = 0; i < length; i++)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}
void merge_sort(int a[], int length)
{
	merge_sort_recursion(a, 0, length - 1);
}

void merge_sort_recursion(int a[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		merge_sort_recursion(a, l, m);
		merge_sort_recursion(a, m + 1, r);

		merge_sorted_arrays(a, l, m, r);
	}
}

void merge_sorted_arrays(int a[], int l, int m, int r)
{
	int left_length = m - l + 1;
	int right_length = r - m;

	int temp_left = (int *)malloc(sizeof(int) * left_length);
	int temp_right = (int *)malloc(sizeof(int) * right_length);
	int** temp1_left = temp_left;
	int** temp1_right = temp_right;
	for (int i = 0; i < left_length; i++)
		temp1_left[i] = (a[l + i]);

	for (int i = 0; i < right_length; i++)
		temp1_right[i] = (a[m + 1 + i]);
	for (int i = 0, j = 0, k = l; k <= r; k++)
	{
		if ((i < left_length) && (j >= right_length || temp1_left[i] <= temp1_right[j]))
		{
			a[k] = temp1_left[i];
			i++;
		}
		else
		{
			a[k] = temp1_right[j];
			j++;
		}
	}/*
	free(temp1_left);
	free(temp1_right);*/
}
