#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int item = strs.size(), length = 0, flag = 0;
        if (item < 1)
            return "";
        string result = "";
        for (;; length++)
        {
            char temp = strs[0][length];
            for (int j = 0; j < item; j++)
            {
                if (strs[j][length] != temp || strs[j][length] == '\0')
                {
                    return result;
                }
            }
            result += temp;
        }
        return result;
    }
};
