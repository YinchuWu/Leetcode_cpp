#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //Key is the number and value is its index in the vector.
        unordered_map<int, int> hash;
        vector<int> result;
        int temp;
        for (int i = 0; i < nums.size(); i++)
        {
            temp = target - nums[i];
            if (hash.find(temp) != hash.end())
            {
                result.push_back(hash[temp]);
                result.push_back(i);
                return result;
            }
            else
            {
                hash[nums[i]] = i;
            }
        }
    }
};

