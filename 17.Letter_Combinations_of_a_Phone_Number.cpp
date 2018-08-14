#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> dig(vector<string> str, int a);
void display(vector<string> res);

class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result = {""};
        if (digits.empty())
            return vector<string>();
        vector<string> const table = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < digits.size(); i++)
        {
            int num = digits[i] - '0';
            vector<string> temp;
            string str = table[num];
            for (int k = 0; k < result.size(); ++k)
            {
                for (int j = 0; j < str.size(); ++j)
                {
                    temp.push_back(result[k] + str[j]);
                }
            }
            result.swap(temp);
        }

        return result;
    }
};

void backtrack(vector<string> &res, string digits, vector<string> table, string local, int index);

class Solution2
{
  public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.size() == 0)
            return res;
        string local;
        vector<string> table = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        backtrack(res, digits, table, local, 0);
        return res;
    }
};

void backtrack(vector<string> &res, string digits, vector<string> table, string local, int index)
{
    if (index == digits.size())
    {
        res.push_back(local);
    }

    else
    {
        int num = digits[index] - '0';
        for (int i = 0; i < table[num].size(); ++i)
        {
            local.push_back(table[num][i]);
            backtrack(res, digits, table, local, index + 1);
            local.pop_back();
        }
    }
}

void display(vector<string> res)
{
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
}

int main()
{
    Solution2 A;
    vector<string> res = A.letterCombinations("23");
    display(res);
}
