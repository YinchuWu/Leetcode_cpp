#include <iostream>
#include <vector>
using namespace std;

void topdown(vector<int> &a, int k)
{
  int length = a.size() - 1;
  while (k <= (length / 2))
  {

    if ((2 * k + 1 <= length && a[2 * k] < a[2 * k + 1] && a[k] > a[2 * k]))
    {
      int t = a[k];
      a[k] = a[2 * k];
      a[2 * k] = t;
      k = 2 * k;
    }
    else if (2 * k + 1 <= length && a[2 * k] > a[2 * k + 1] && a[2 * k + 1] < a[k])
    {
      int t = a[k];
      a[k] = a[2 * k + 1];
      a[2 * k + 1] = t;
      k = 2 * k + 1;
    }
    else
      return;
  }
  return;
}

void downtop(vector<int> &a)
{
  int t = a.size() - 1;
  while (t > 1 && a[t / 2] > a[t])
  {
    int temp = a[t / 2];
    a[t / 2] = a[t];
    a[t] = temp;
    t /= 2;
  }
}

void make_heap(vector<int> &a)
{
  int length = a.size() - 1;
  for (int i = length / 2; i >= 1; i--)
  {
    topdown(a, i);
  }
}

void push_heap(vector<int> &a, int k)
{
  a.push_back(k);
  downtop(a);
}

void pop_heap(vector<int> &a)
{
  a[1] = a[a.size() - 1];
  a.pop_back();
  topdown(a, 1);
}

void display(vector<int> t)
{
  for (int i = 1; i < t.size(); i++)
    cout << t[i] << ' ';
}

int main(int argc, char const *argv[])
{
  vector<int> t = {0, 16, 4, 10, 14, 7, 9, 3, 2, 8};
  make_heap(t);
  display(t);
  cout << endl;
  push_heap(t, 1);
  display(t);
  cout << endl;
  pop_heap(t);
  display(t);
  cout << endl;
  return 0;
}
