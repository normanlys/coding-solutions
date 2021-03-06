#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> stack;
        for (const char& c: s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stack.push(c);
            }
            else
            {
                if (stack.empty())
                    return false;

                if (c == ')' && stack.top() == '(')
                    stack.pop();
                else if (c == ']' && stack.top() == '[')
                    stack.pop();
                else if (c == '}' && stack.top() == '{')
                    stack.pop();
                else 
                    return false;
            }
        }

        return stack.empty();
    }
};

int main(int argc, char const *argv[])
{
    bool result = Solution().isValid("}");
    cout << result << endl;
    return 0;
}
