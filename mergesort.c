
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[],
			int low, int high)
{
	if (low < high)
	{
		int mid = low + (high - low) / 2;


		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);

		merge(arr, low, mid, high);
	}
}
void merge(int arr[], int low,
		int mid, int high)
{
	int i, j, k;
	int n1 = mid - low + 1;
	int n2 = high - mid;


	int Left[n1], Right[n2];


	for (i = 0; i < n1; i++)
		Left[i] = arr[low + i];
	for (j = 0; j < n2; j++)
		Right[j] = arr[mid + 1 + j];


	i = 0;
    j = 0;
    k = low;

	while (i < n1 && j < n2)
	{
		if (Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			i++;
		}
		else
		{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}


	while (i < n1) {
		arr[k] = Left[i];
		i++;
		k++;
	}


	while (j < n2)
	{
		arr[k] = Right[j];
		j++;
		k++;
	}
}





int main()
{
	int arr[50];
	int arr_size;
	printf("enter total number of items in the array\n");
	scanf("%d",&arr_size);

	printf("enter the items in the unsorted array\n");

	for(int i=0;i<arr_size;i++){

	scanf("%d",&arr[i]);

	}


	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	for(int i=0;i<arr_size;i++){
	printf("%d ",arr[i]);
	}
	return 0;
}
