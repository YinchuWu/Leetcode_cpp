#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k==1)
            return head;
        ListNode *in = new ListNode(0), *out = head;
        in->next = head;
        head = in;
        for (;;)
        {
            ListNode *temp = in->next;
            for (int i = 0; i < k; i++)
            {
                out = out->next;
                if (out == NULL && i != k - 1)
                    return head->next;
            }
            trans(in, k, out);
            in = temp;
            if (out == NULL)
                return head->next;
        }
    }
};

void trans(ListNode *in, int k, ListNode *out)
{
    if (k == 1)
    {
        in->next->next = out;
        return;
    }
    ListNode *b = in->next;
    in->next = in->next->next;
    b->next = out;
    trans(in, --k, b);
}