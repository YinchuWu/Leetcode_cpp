#include <iostream>
#include <vector>
using namespace std;

class Solution1
{
  public:
    int maxArea(vector<int> &height)
    {
        int maxwater = 0;
        int b = 0, e = height.size();
        while (b < e)
        {
            int h = min(height[b], height[e]);
            maxwater = max(h * (e - b), maxwater);
            while (height[b] <= h && b < e)
                ++b;
            while (height[e] <= h && b < e)
                --e;
        }
        return maxwater;
    }
};

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


