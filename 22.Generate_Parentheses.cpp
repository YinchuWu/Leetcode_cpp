#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

void step(vector<string> &r, string result, int t, int n);
void adding(vector<string> &r, string result, int m, int n);

class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        adding(result, "", 0, n);
        return result;
    }
};

void step(vector<string> &r, string result, int t, int n)
{
    if (t == n)
    {
        while (result.size() < 2 * n)
            result += ")";
        r.push_back(result);
        return;
    }
    step(r, result + "(", t + 1, n);
    if (result.size() < 2 * t)
    {
        step(r, result + ")", t, n);
    }
}

void adding(vector<string> &r, string result, int m, int n)
{
    if (m == 0 && n == 0)
    {
        r.push_back(result);
        return;
    }
    if (m > 0)
        adding(r, result + ')', m - 1, n);
    if (n > 0)
        adding(r, result + '(', m + 1, n - 1);
}

int main()
{
    Solution A;
    vector<string> res = A.generateParenthesis(3);
    cout << res[1];
    return 0;
}
