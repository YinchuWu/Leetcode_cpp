#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool cmp(ListNode *a, ListNode *b)
{
    return a->val > b->val;
}

class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode head(0);
        ListNode *cur = &head;
        vector<ListNode *> result;
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i])
                result.push_back(lists[i]);
        }
        make_heap(result.begin(), result.end(), cmp);
        while (!result.empty())
        {
            cur->next = result.front();
            pop_heap(result.begin(), result.end(), cmp);
            result.pop_back();
            cur = cur->next;
            if (cur->next)
            {
                result.push_back(cur->next);
                push_heap(result.begin(), result.end(), cmp);
            }
        }
        return head.next;
    }
};
