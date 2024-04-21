// My own implementation of Merge Sort in C++
#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

using namespace	std;
// UTILITY FUNCTIONS
void	printVector(vector<int> &sortedArray)
{
	for (vector<int>::iterator it = sortedArray.begin(); it != sortedArray.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

vector<int> checkArguments(char **argv)
{
	long	value;
	char	*endPtr;

	vector<int> arguments;
	while (argv && *argv)
	{
		value = strtol(*argv, &endPtr, 10);
		// if (*endPtr != '\0')
		// {
		// 	throw invalid_argument("Not a integer value");
		// }
		// if (value < 0 || value > INT_MAX)
		// 	throw invalid_argument("Not a positive integer");
		++argv;
		arguments.push_back(value);
	}
	return (arguments);
}

void	merge(vector<int>& array, int left, int mid, int right)
{
	int	leftSize;
	int	rightSize;
	int	leftIndex;
	int	rightIndex;
	int	mergedIndex;

	leftSize = mid - left + 1;
	rightSize = right - mid;
	vector<int> leftArray(leftSize);
	vector<int> rightArray(rightSize);
	for (int i = 0; i < leftSize; i++)
	{
		leftArray[i] = array[left + i];
	}
	for (int i = 0; i < rightSize; i++)
	{
		rightArray[i] = array[mid + i + 1];
	}
	leftIndex = 0;
	rightIndex = 0;
	mergedIndex = left;
	while (leftIndex < leftSize && rightIndex < rightSize)
	{
		if (leftArray[leftIndex] <= rightArray[rightIndex])
		{
			array[mergedIndex] = leftArray[leftIndex];
			leftIndex++;
		}
		else
		{
			array[mergedIndex] = rightArray[rightIndex];
			rightIndex++;
		}
		mergedIndex++;
	}
	while (leftIndex < leftSize)
	{
		array[mergedIndex] = leftArray[leftIndex];
		leftIndex++;
		mergedIndex++;
	}
	while (rightIndex < rightSize)
	{
		array[mergedIndex] = rightArray[rightIndex];
		rightIndex++;
		mergedIndex++;
	}
}

void	mergeSort(vector<int>& array, int start, int end)
{
	int	mid;

	if (start >= end)
		return ;
	mid = start + (end - start) / 2;
	mergeSort(array, start, mid);
	mergeSort(array, mid + 1, end);
	merge(array, start, mid, end);
}

int	main(int ac, char **argv)
{
	try
	{
		if (ac < 2)
			throw out_of_range("Not enough arguments");
		vector<int> array = checkArguments(argv);
		mergeSort(array, 0, array.size() - 1);
		printVector(array);
	}
	catch (const exception &e)
	{
		cerr << e.what() << '\n';
	}
	return (0);
}