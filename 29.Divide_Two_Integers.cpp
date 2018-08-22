#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;

class Solution
{
  public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == INT_MIN)
            return 1;
        if (dividend == 0 || divisor == INT_MIN)
            return 0;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        int res = 0;
        divisor = fabs(divisor);
        if (dividend == INT_MIN)
        {
            res++;
            dividend += divisor;
        }
        dividend = fabs(dividend);
        while (dividend >= divisor)
        {
            long long temp = divisor, mul = 1;
            while (dividend >= (temp << 1))
            {
                temp <<= 1;
                mul <<= 1;
            }
            dividend -= temp;
            res += mul;
        }
        return res * sign;
    }
};

int main(int argc, char const *argv[])
{
    Solution A;
    cout << A.divide(-2147483648, 1);
    return 0;
}
