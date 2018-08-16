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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode(0), *temp = result;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        temp->next = (l1)?l1:l2;
        return result->next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *a = new ListNode(5);
    cout << a->val;
}
