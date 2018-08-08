#include <iostream>
#include <string>
using namespace std;

class Solution
{
  public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1)
            return s;
        const int length = s.size();
        string *str = new string[numRows];

        int row = 0, step = 1;
        for (int i = 0; i < length; i++)
        {
            str[row].push_back(s[i]);
            if (row == 0)
                step = 1;
            else if (row == numRows - 1)
                step = -1;
            row += step;
        }
        s.clear();
        for(int i = 0;i<numRows;i++)
        {
            s.append(str[i]);
        }
        delete[] str;
        return s;
    }
};

class Solution1
{
  public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string result = "";
        int length = s.size();
        int step = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++)
        {
            int j = i;
            result += s[j];
            j += step - 2 * i;
            if (i == numRows - 1)
                j += 2 * i;
            while (j < length)
            {
                result += s[j];
                if (i != 0 && i != numRows - 1)
                {
                    j += 2 * i;
                    if (j >= length)
                        break;
                    result += s[j];
                }
                j += step - 2 * i;
                if (i == numRows - 1)
                    j += 2 * i;
            }
        }
        return result;
    }
};

int main()
{
    Solution a;
    cout << a.convert("A", 1);
}