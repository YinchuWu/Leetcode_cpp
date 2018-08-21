#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> cal_next(string a) //calculate longest same prefix and postfix
{
    vector<int> next(a.size(), 0);
    for (int i = 1; i < a.size(); ++i)
    {
        if (a[i] == a[next[i - 1]])
        {
            next[i] = (next[i - 1] + 1);
        }

        else
        {
            int temp = next[i - 1];
            while (temp > 0)
            {
                temp = next[temp - 1];
                if (a[temp] == a[i])
                {
                    next[i] = temp + 1;
                    break;
                }
            }
        }
    }
    next.insert(next.begin(), -1);
    return next;
}

class Solution
{
  public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        int length1 = haystack.size(), length2 = needle.size();
        int i = 0, j = 0;
        vector<int> next = cal_next(needle);
        while (i < length1 && j < length2)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }

            else
            {
                j = next[j];
            }
        }
        if (j == length2)
            return i - j;
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    string a = "aqaa";
    vector<int> t = cal_next(a);
    for (int i = 0; i < t.size(); ++i)
        cout << t[i];
    Solution A;
    cout<<A.strStr("hello","ll");
    return 0;
}
