#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
  public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        int n = s.size(), cnt = words.size();
        if (n == 0 || cnt == 0)
            return res;

        unordered_map<string, int> dict;
        for (int i = 0; i < cnt; ++i)
            ++dict[words[i]];

        int wl = words[0].size();
        if (n < wl)
        {
            return res;
        }
        for (int i = 0; i < wl; ++i)
        {
            unordered_map<string, int> temp;
            int left = i, count = 0;
            for (int j = i; j <= n - wl; j += wl)
            {
                string str = s.substr(j, wl);
                if (dict.count(str))
                {
                    ++temp[str];
                    if (temp[str] <= dict[str])
                        count++;

                    else
                    {
                        while (temp[str] > dict[str])
                        {
                            string str1 = s.substr(left, wl);
                            temp[str1]--;
                            if (str1 != str)
                                count--;
                            ;
                            left += wl;
                        }
                    }
                    if (count == cnt)
                    {
                        res.push_back(left);
                        temp[s.substr(left, wl)]--;
                        left += wl;
                        count--;
                    }
                }

                else
                {
                    temp.clear();
                    count = 0;
                    left = j + wl;
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    string a = "abababab";
    vector<string> b = {"ab", "ba"};
    Solution A;
    vector<int> res = A.findSubstring(a, b);
    cout << res.size();
    return 0;
}
