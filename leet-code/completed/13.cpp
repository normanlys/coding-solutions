#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> romanValueMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int sum = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            int currentCharValue = romanValueMap[s[i]];
            int nextCharValue = romanValueMap[s[i+1]];
            if (currentCharValue < nextCharValue)
            {
                sum -= currentCharValue;
            }
            else
            {
                sum += currentCharValue;
            }
        }

        return sum + romanValueMap[s[s.length()-1]];
    }
};

int main(int argc, char const *argv[])
{
    vector<string> tests{"III", "VI", "IV", "CD"};
    for (const string& s: tests)
    {
        int result = Solution().romanToInt(s);
        cout << result << endl;
    }
    return 0;
}
