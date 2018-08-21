#include <string>
#include <iostream>
using namespace std;

class Solution
{
  public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        int length1 = haystack.size(), length2 = needle.size();
        for (int i = 0; i < length1 - length2 + 1; ++i)
        {
            for (int j = 0; j < length2; ++j)
            {
                if (haystack[i + j] != needle[j])
                    break;
                if (j == length2 - 1)
                    return i;
            }
        }
        return -1;
    }
};