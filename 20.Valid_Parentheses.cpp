#include <stack>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
  public:
    bool isValid(string s)
    {
        stack<char> table;
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
            case '{':
            case '[':
                table.push(s[i]);
                break;
            case ')':
                if (table.empty() || table.top() != '(')
                    return false;
                else
                    table.pop();
                break;
            case '}':
                if (table.empty() || table.top() != '{')
                    return false;
                else
                    table.pop();
                break;
            case ']':
                if (table.empty() || table.top() != '[')
                    return false;
                else
                    table.pop();
                break;
            }
        }
        return table.empty();
    }
};