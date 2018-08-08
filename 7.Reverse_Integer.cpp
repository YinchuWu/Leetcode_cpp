#include <iostream>
#include <limits.h>
using namespace std;

class Solution
{
  public:
    int reverse(int x)
    {
        long y = 0;
        while (x)
        {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return (y < INT_MIN || y > INT_MAX) ? 0 : y;
    }
};

int main()
{
    Solution a;
    cout << a.reverse(-122);
}