#include <string>
#include <iostream>
using namespace std;

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";
        if (s.size() == 1)
            return s;

        int b, maxlen = 0;
        for (int i = 0; i < s.size();)
        {
            if (s.size() - i <= maxlen / 2)
                break;
            int k = i, j = i;
            while (k < s.size() - 1 && s[k + 1] == s[k])
                k++;
            i = k + 1;
            while (k < s.size() && j >= 0 && s[k] == s[j])
            {
                k++;
                j--;
            }
            if (maxlen < k - j - 1)
            {
                maxlen = k - j - 1;
                b = j + 1;
            }
        }
        return s.substr(b, maxlen);
    }
};

int main()
{
    Solution a;
    cout << a.longestPalindrome("bccb");
}