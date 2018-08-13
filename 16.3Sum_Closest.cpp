#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() < 3)
            return 0;
        int length = nums.size(), dis = abs(nums[1] + nums[2] + nums[0] - target), res = nums[1] + nums[2] + nums[0];
        for (int i = 0; i < length - 2; ++i)
        {
            int b = i + 1, e = length - 1;
            while (b < e)
            {
                int sum = nums[b] + nums[e] + nums[i];
                if(abs(sum - target)<dis)
                {
                    dis = abs(sum-target);
                    res = sum;
                }
                if (sum < target)
                    ++b;
                else if (sum > target)
                    --e;
                else
                    return target;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> a = {0,1,2};
    Solution A;
    cout << A.threeSumClosest(a, 3);
}