#include <iostream>
#include <vector>
#include <algorithm>

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
    for (auto n : arr)
        cout << n << endl;
}

int GetPivotIndex1(vector<int>& arr, const int& start, const int& length)
{
    return start;
}

void QuickSort(vector<int>& arr, const int& start, const int& length)
{
    if (length < 2)
        return;

    int pivotIndex = GetPivotIndex1(arr, start, length);
    int pivot = arr[pivotIndex];
    swap(arr[start], arr[pivotIndex]);

    int i = start;
    int j = start;
    for (int k = start + 1; k < length; k++)
    {
        if (arr[k] < pivot)
        {
            swap(arr[k], arr[i+1]);
            i++;
        }
        j++;
    }
    swap(arr[pivotIndex], arr[i]);
    cout << "pivotIndex " << pivotIndex << " i " << i << endl;

    QuickSort(arr, start, pivot - start);
    QuickSort(arr, pivot + 1, length - start - 1);
}

int main(int argc, char const *argv[])
{
    Print("start");
    vector<int> arr = {1, 4, 3};
    QuickSort(arr, 0, arr.size());
    
    Print("Sorted");
    
    Print(arr);
    return 0;
}
