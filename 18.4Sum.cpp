#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        int length = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < length - 3; ++i)
        {
            for (int j = i + 1; j < length - 2; j++)
            {
                int b = j + 1, e = length - 1, temp = nums[i] + nums[j];
                while (b < e)
                {
                    if (nums[b] + nums[e] + temp < target)
                        ++b;
                    else if (nums[b] + nums[e] + temp > target)
                        --e;

                    else
                    {
                        result.push_back({nums[i], nums[j], nums[b], nums[e]});
                        ++b;
                        --e;
                        while (b < e && nums[b] == nums[b - 1])
                            ++b;
                        while (b < e && nums[e] == nums[e + 1])
                            --e;
                    }
                }
                while (nums[j + 1] == nums[j] && j < length - 2)
                    ++j;
            }
            while (nums[i + 1] == nums[i] && i < length - 3)
                ++i;
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> result;
    Solution A;
    result = A.fourSum(nums, 0);
}