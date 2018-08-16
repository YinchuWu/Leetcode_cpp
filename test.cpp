#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

static bool heapcomp(ListNode *a, ListNode *b)
{
    return a->val > b->val;
}
/*
class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

    }
};
*/
bool cmp(int a, int b) {return a > b;}

void display(vector<int> const a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
}

int main(int argc, char const *argv[])
{
    vector<int> a = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    make_heap(a.begin(), a.end(), cmp);
    display(a);
    cout<<endl;
    sort_heap(a.begin(), a.end(), cmp);
    display(a);
    cout << endl;
    pop_heap(a.begin(),a.end(),cmp);
    a.pop_back();
    display(a);
    return 0;
}
