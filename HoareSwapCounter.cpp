#include <bits/stdc++.h>
using namespace std;

// global counter to track swaps
int swapCount = 0;
// actual quiucksort partition
int hoarePartition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low - 1, j = high + 1;

	while (true) {
		do {
			i++;
		} while (arr[i] < pivot);
		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
			return j;
		// counter increment
		swapCount++;
		swap(arr[i], arr[j]);
	}
}

// actual sorting function
void quickSort(int arr[], int low, int high)
{
	// comparisons
	if (low < high) {
		int pi = hoarePartition(arr, low, high);
		quickSort(arr, low, pi);
		quickSort(arr, pi + 1, high);
	}
}

// Function to print the array
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main()
{
	// array can be any size, just adjust bounds accordingly
	int arr[150];
	int n = sizeof(arr) / sizeof(arr[0]);
	// if changing size of array set i below equal to size - 1
	for (int i = 149; i >= 0; i--) {
		arr[n - 1 - i] = i + 1;
	}

	// displays sorted array
	quickSort(arr, 0, n - 1);
	cout << "Total swap in QuickSort using hoare partition " << swapCount << "\n";
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}