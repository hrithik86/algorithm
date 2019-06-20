#include <iostream>
#include <algorithm>
using namespace std;

// Function to print all distinct triplet in the array with given sum
void printAllTriplets(int arr[], int n, int sum)
{
	// sort the array in ascending order
	sort (arr, arr + n);

	// check if triplet is formed by arr[i] and a pair from 
	// sub-array arr[i+1..n)
	for (int i = 0; i <= n - 3; i++)
	{
		// remaining sum
		int k = sum - arr[i];

		// maintain two indices pointing to end-points of the 
		// sub-array arr[i+1..n)
		int low = i + 1, high = n - 1;

		// loop till low is less than high
		while (low < high)
		{
			// increment low index if total is less than the remaining sum
			if (arr[low] + arr[high] < k)
				low++;

			// decrement high index is total is more than the remaining sum
			else if (arr[low] + arr[high] > k)
				high--;

			// triplet with given sum found
			else
			{
				// print the triplet
				cout << "(" << arr[i] << " " << arr[low] << " " << 
						arr[high] << ")\n";

				// increment low index and decrement high index
				low++, high--;
			}
		}
	}
}

// Find Triplet with given sum in an array
int main()
{
	int arr[] = { 12, 3, 6, 1, 6, 9 };
	int sum = 24;

	int n = sizeof(arr) / sizeof(arr[0]);

	printAllTriplets(arr, n, sum);

	return 0;
}