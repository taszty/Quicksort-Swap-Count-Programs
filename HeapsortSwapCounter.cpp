#include <iostream>
using namespace std;

int swapCount = 0; //global varibale to count number of swaps

// create heap method
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		{ 
		swap(arr[i], arr[largest]);
		swapCount++;
		}
		heapify(arr, n, largest);
	}
}

// heap sorting method
void heapSort(int arr[], int n)
{

	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		// Move current root to end
		{
		swap(arr[0], arr[i]);
		swapCount++;
		}
		heapify(arr, i, 0);
	}
}

// print array method
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}


int main()
{
	// array can be any size
	int arr[150];
	int n = sizeof(arr) / sizeof(arr[0]);
	// if changing size of array be sure to make i below array size - 1
	for (int i = 149; i >= 0; i--) {
		arr[n - 1 - i] = i + 1;
	}

	// call methods
	heapSort(arr, n);
	cout << "Total swap in  heapsort  " << sw << "\n";
	cout << "Sorted array is \n";
	// display output
	printArray(arr, n);
}