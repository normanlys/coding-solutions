#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if (x < 0)
            return false;
        if (x < 10)
            return true;


        string s = to_string(x);

        string reversed(s);
        reverse(reversed.begin(), reversed.end());
        for (int i = 0; i < s.length()/2; i++)
        {
            // cout << s[i] << " " << reversed[i] << endl;
            if (s[i] != reversed[i])
                return false;
        }
        return true;
    }
};

int main()
{
    int numberList[4] = {11,299,3003,40404};
    for (const int& n: numberList) 
    {
        bool result = Solution().isPalindrome(n);
        cout << result << endl;
    }
}