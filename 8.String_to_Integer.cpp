#include <string>
#include <iostream>
#include <limits.h>
using namespace std;

class Solution
{
  public:
    int myAtoi(string str)
    {
        int b = 0, flag = 1;
        long result = 0;
        while (str[b] == ' ' || str[b] == '-' || str[b] == '+')
        {
            b++;
            if (str[b - 1] == '-' || str[b - 1] == '+')
            {
                flag = (str[b - 1] == '-') ? -flag : flag;
                break;
            }
        }

        while (str[b] >= '0' && str[b] <= '9')
        {
            result = result * 10 + str[b++] - '0';
            if (result > INT_MAX)
            {
                return (flag == -1) ? INT_MIN : INT_MAX;
            }
        }
        result *= flag;
        return result;
    }
};

int main()
{
    Solution a;
    cout << a.myAtoi("-4193 with words");
}