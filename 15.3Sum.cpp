#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result = {};
        if (nums.size() < 3)
            return result;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            int target = -nums[i];
            int b = i + 1, e = nums.size() - 1;
            while (b < e)
            {
                int sum = nums[b] + nums[e];
                if (sum < target)
                    ++b;
                else if (sum > target)
                    --e;

                else
                {
                    vector<int> temp = {-target, nums[b], nums[e]};
                    result.push_back(temp);
                    while (nums[b] == temp[1] && b < e)
                        ++b;
                    while (nums[e] == temp[2] && b < e)
                        --e;
                }
            }
            while (i < nums.size() - 1 && nums[i + 1] == nums[i])
                ++i;
        }
        return result;
    }
};