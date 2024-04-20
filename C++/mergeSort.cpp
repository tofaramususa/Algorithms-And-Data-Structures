//My own implementation of Merge Sort in C++
#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;
//UTILITY FUNCTIONS
void printVector(vector<int> sortedArray)
{
	for(vector<int>::iterator it = sortedArray.begin(); it != sortedArray.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

vector<int> checkArguments(char **argv)
{
	vector<int> arguments;
	while(argv && *argv)
	{
		long value;
		char *endPtr;
		value = strtol(*argv, &endPtr, 10);
		if(endPtr != '\0')
		{
			throw invalid_argument("Not a integer value");
		}
		if(value < 0 || value > INT_MAX)
			throw invalid_argument("Not a positive integer");
		++argv;
		arguments.push_back(value);
	}
}

vector<int> mergeSort(vector<int> array, vector<int>::iterator start, vector<int>::iterator end)
{
	


}







int main(int ac, char **argv)
{
	try
	{
		if(ac < 2)
			throw out_of_range("Not enough arguments");
		vector<int> array = checkArguments(argv);
		vector<int>::iterator start = array.begin();
		vector<int>::iterator end = array.end() - 1;
		vector<int> sortedArray = mergeSort(array, start, end);
		printVector(sortedArray);
	}
	catch(const exception& e)
	{
		cerr << e.what() << '\n';
	}
	
}