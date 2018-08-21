#include <vector>
#include <iostream>
using namespace std;

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int length = 0, temp = nums[0];
        for (int target = 0; target < nums.size(); ++target)
        {
            if (nums[target] != temp)
            {
                temp = nums[target];
                nums[++length] = temp;
            }
        }
        return ++length;
    }
};

class Solution2
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int count = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
                count++;
            else
                nums[i - count] = nums[i];
        }
        return nums.size() - count;
    }
};

void display(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
}

int main(int argc, char const *argv[])
{
    vector<int> a = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution A;
    cout << A.removeDuplicates(a);
    display(a);
    return 0;
}
