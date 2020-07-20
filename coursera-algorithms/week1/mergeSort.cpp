#include <iostream>
#include <vector>

using namespace std;

int c = 0;

void merge(vector<int>& arr, int l, int r, int mid)
{
    
}

void mergeSort(vector<int>& arr, int l, int r)
{
    cout << c << endl;
    c++;
    if (l >= r)
        return;
    
    int mid = (r - l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, r, mid);

}

int main(int argc, char const *argv[])
{
    vector<int> arr = { 87, 4 };

    mergeSort(arr, 0, arr.size() - 1);

    for (int n : arr)
        cout << n << endl;
    return 0;
}
