#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int b = 0, e = height.size() - 1;
        int maxwater = 0, temp = 0;
        while (b != e)
        {
            temp = min(height[b], height[e]) * (e - b);
            maxwater = max(maxwater, temp);
            if (height[b] > height[e])
                --e;
            else
                ++b;
        }
        return maxwater;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> b({1, 8, 6, 2, 5, 4, 8, 3, 7});
    cout << a.maxArea(b);
    return 0;
}
