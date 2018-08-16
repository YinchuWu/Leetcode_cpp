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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *cur = new ListNode(0);
        cur->next = head;
        head = cur;
        while (cur->next != NULL && cur->next->next != NULL)
        {
            ListNode *t = cur->next;
            cur->next = t->next;
            cur = cur->next;
            t->next = cur->next;
            cur->next = t;
            cur = cur->next;
        }
        return head->next;
    }
};

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *temp = head;
    for (int i = 1; i < 10; i++)
    {
        head->next = new ListNode(i);
        head = head->next;
    }
    head = temp;
    while (head!=NULL)
    {
        cout << head->val;
        head = head->next;
    }
    cout<<endl;
    Solution A;
    head = A.swapPairs(temp);
    while(head!=NULL)
    {
        cout<<head->val;
        head = head->next;
    }
}