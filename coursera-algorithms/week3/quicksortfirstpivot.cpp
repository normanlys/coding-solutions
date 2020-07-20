#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;

void Print(const int& message)
{
    cout << message << endl;
}

void Print(const string& message)
{
    cout << message << endl;
}

void Print(const vector<int>& arr)
{
    for (int n : arr)
        cout << n << ", ";
    cout << "\n";
}

int GetPivotIndex(vector<int>& arr, const int& low, const int& high)
{
    int midIndex = (high+low)/2;
    int first = arr[low];
    int mid = arr[midIndex];
    int last =  arr[high];

    vector<int> pivots = {first, mid, last};
    sort(pivots.begin(), pivots.end());
    
    const int pivot = pivots[1];
    if (pivot == first)
        return low;
    else if (pivot == mid)
        return midIndex;
    else
        return high;
}

void QuickSort(vector<int>& arr, const int& low, const int& high, int& comparisons)
{
    if (high <= low)
        return;

    comparisons += high - low;

    const int pivotIndex = GetPivotIndex(arr, low, high);
    const int pivot = arr[pivotIndex];
    swap(arr[low], arr[pivotIndex]);

    int i = low;
    int j = low;
    for (int k = low + 1; k <= high; k++)
    {
        if (arr[k] < pivot)
        {
            swap(arr[k], arr[i+1]); 
            i++;
        }
        j++;
    }

    swap(arr[low], arr[i]);

    QuickSort(arr, low, i - 1, comparisons);
    QuickSort(arr, i + 1, high, comparisons);
}

int main(int argc, char const *argv[])
{
    ifstream file("quicksort.txt");
    vector<int> arr = {};
    int n;
    while (file >> n)
        arr.push_back(n);

    // vector<int> arr = {3, 6, 1};

    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    int comparisons = 0;
    QuickSort(arr, 0, arr.size()-1, comparisons);
    
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != sortedArr[i])
            throw;
    }
    
    Print(arr);
    Print(comparisons);


    return 0;
}
