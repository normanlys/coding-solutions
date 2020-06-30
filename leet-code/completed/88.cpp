#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m;
        for (int j = 0; j < n; ++j)
        {
            for (int i = 0; i < k; ++i)
            {
                if (nums1[i] > nums2[j])
                {
                    nums1.insert(nums1.cbegin() + i, nums2[j]);
                    nums1.pop_back();
                    goto nextNums1;
                }
            }
            *(nums1.begin() + k) = nums2[j];
            
            nextNums1:;
            ++k;
        }
    }
};