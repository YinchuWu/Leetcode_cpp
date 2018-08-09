#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Solution
{
  public:
    bool isPalindrome(int x)
    {
        if(x<0 || (x%10 == 0 && x!=0))return false;
        int temp = 0;
        while(x>temp)
        {
            temp = temp*10 + x%10;
            x/=10;
        }
        if(x==temp || x == temp/10)return true;
        return false;
    }
};

class Solution1
{
  public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int power = -1, temp = x;
        while (temp != 0)
        {
            temp /= 10;
            power += 1;
        }
        power = pow(10, power);
        while (x != 0 && (x / power == x % 10))
        {
            x %= power;
            x /= 10;
            power /= 100;
        }
        if (x == 0)
            return true;
        return false;
    }
};

int main()
{
    Solution a;
    cout << a.isPalindrome(121);
}