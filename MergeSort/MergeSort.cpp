#include <iostream>

void MergeSort(int* arr, int min, int max); // a function which applies the reccursive merge sort 
void Merge(int* arr, int min, int max, int div); // a function which merges two sorted arrays into a single sorted array

int main()
{
	int arr[20] = { 3,4,6,3,2,1,3,7,8,9,10,0,21,43,23,12,11,9,8,7 };
	
	MergeSort(arr, 0, 20);

	system("pause");
	return 0;
}

void MergeSort(int* arr, int min, int max)
{
	if (min == max)
		return;
	//find the middle of the array
	int mid = (min + max) / 2;
	//call the merge sort for the first half of the array
	MergeSort(arr, min, mid);
	//do the same for the second half
	MergeSort(arr, mid+1, max);
	//merge the two sorted halfs
	Merge(arr, min, max, mid);
	//all this is done recursivly until the who array is broken down into maximal number of sub-arrays which get
	//progressivly sorted and merged into a now sorted array

}

void Merge(int* arr, int min, int max, int div)
{
	//div is the division line between the two merging sub-arrays
	//calculating the size of the sub arrays
	int arr1_size = div-min + 1;
	int arr2_size = max - div;
	int* l = new int[arr1_size];
	int* r = new int[arr2_size];

	//splitting the main array
	for (int i = 0; i < arr1_size; i++)
		l[i] = arr[min + i];
	for (int i = 0; i < arr2_size; i++)
		r[i] = arr[div+1+ i];

	//keeping track of counters
	int i = 0, j = 0, k = min;

	//merging two sub-arrays into the array so that they remain sorted 
	while ((i < arr1_size) && (j < arr2_size))
	{
		if (l[i] >= r[j])
		{
			arr[k] = r[j];
			j++;
		}
		else
		{
			arr[k] = l[i];
			i++;
		}
		k++;

	}
	//adding the remaining elemtents of the larger array

	while (i < arr1_size)
	{
		arr[k] = l[i];
		i++;
		k++;
	}

	while (j < arr2_size)
	{
		arr[k] = r[j];
		j++;
		k++;
	}
	delete[] l;
	delete[] r;

}