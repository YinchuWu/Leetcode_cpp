#include <vector>
#include <iostream>
#include <typeinfo>
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        vector<ListNode *> temp;
        int length = 1;
        ListNode *p = head;
        temp.push_back(p);
        while (p->next != NULL)
        {
            length++;
            temp.push_back(p->next);
            p = p->next;
        }
        int pos = length - n - 1;
        if (pos < 0)
        {
            head = head->next;
            return head;
        }
        else if(n == 1)
        {
            temp[pos]->next = NULL;
            return head;
        }
        temp[pos]->next = temp[pos + 2];
        return head;
    }
};

class Solution1
{
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp=head,*beg = head;
        for(int i = 0; i < n; i++)
        {
            temp = temp->next;
        }
        if(temp == NULL)
        {
            return head->next;
        }
        while(temp->next!=NULL)
        {
            temp=temp->next;
            beg = beg->next;
        }
        beg->next = beg->next->next;
        return head;
        
    }
};
