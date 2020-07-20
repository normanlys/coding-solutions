#include <iostream>
#include <string>
#define toDigit(c) (c-'0')
#define toChar(i) ('0'+i)

using namespace std;

string addition(string first, string second)
{
    string& larger = first.size() > second.size() ? first : second;
    string& smaller = first.size() > second.size() ? second : first;

    string result = "";
    bool overTen = false;
    for (int i = larger.size() - 1; i > -1; --i)
    {
        int j = i - (larger.size() - smaller.size());
        int added;
        if (j < 0)
        {
            added = toDigit(larger[i]) + (overTen ? 1 : 0);
        }
        else 
        {
            added = toDigit(larger[i]) + toDigit(smaller[j]) + (overTen ? 1 : 0);
        }

        if (added > 9)
        {
            overTen = true;
            added -= 10;
        }
        else 
        {
            overTen = false;
        }

        result.insert(result.cbegin(), toChar(added));
    }
    
    if (overTen)
        result.insert(result.cbegin(), '1');

    return result;
}



string karatsubaMultiplication(string first, string second)
{
    int size = first.size();

    if (size != second.size())
        throw;

    if (size < 2)
    {
        int result = stoi(first) * stoi(second);
        return to_string(result);
    }
    else 
    {
        string a = first.substr(0, size/2);
        string b = first.substr(size/2, size/2);
        string c = second.substr(0, size/2);
        string d = second.substr(size/2, size/2);

        string ac = karatsubaMultiplication(a,c);
        string adPlusBC = addition(karatsubaMultiplication(a,d), karatsubaMultiplication(b,c));
        string bd = karatsubaMultiplication(b,d);

        ac.append(string(size, '0'));
        adPlusBC.append(string(size/2, '0'));

        return addition(addition(ac, adPlusBC), bd);
    }
}

int main(int argc, char const *argv[])
{
    string a = "3141592653589793238462643383279502884197169399375105820974944592";
    string b = "2718281828459045235360287471352662497757247093699959574966967627";

    cout << karatsubaMultiplication(a, b) << endl;
    return 0;
}
