#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        int length = s.size();
        unordered_map<char, int> hash;
        int maxlen = 0;
        int position = -1;
        for (int i = 0; i < length; i++)
        {
            if (hash.find(s[i]) != hash.end())
            {
                if (hash[s[i]] > position)
                {
                    maxlen = max(maxlen, i - 1 - position);
                    position = hash[s[i]];
                }
            }
            hash[s[i]] = i;
        }
        maxlen = max(maxlen, length - 1 - position);
        return maxlen;
    }
};

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> hash(256, -1);
        int pos = -1, maxlen = 0;
        for (int i = 0; i < s.size(); i++ 1)
        {
            if (hash[s[i]] > pos)
                pos = hash[s[i]];
            hash[s[i]] = i;
            maxlen = max(maxlen, i - pos);
        }
        return maxlen;
    }
};