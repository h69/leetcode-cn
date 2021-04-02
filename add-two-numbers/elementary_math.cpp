#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode();
    ListNode* p = result;
    ListNode* q = nullptr;

    while (true) {
      if (l1 == nullptr) {
        q = l2;
        break;
      }

      if (l2 == nullptr) {
        q = l1;
        break;
      }

      p->val = l1->val + l2->val + p->val;

      if (l1->next != nullptr || l2->next != nullptr || p->val >= 10) {
        p->next = new ListNode();
        p->next->val = p->val / 10;
        p->val = p->val % 10;
        p = p->next;
      }

      l1 = l1->next;
      l2 = l2->next;
    }

    while (q != nullptr) {
      p->val = q->val + p->val;

      if (q->next != nullptr || p->val >= 10) {
        p->next = new ListNode();
        p->next->val = p->val / 10;
        p->val = p->val % 10;
        p = p->next;
      }

      q = q->next;
    }

    return result;
  }
};

int main() {
  ListNode* l1 = new ListNode();
  l1->val = 0;
  l1->next = new ListNode();
  l1->next->val = 9;
  l1->next->next = new ListNode();
  l1->next->next->val = 9;

  ListNode* l2 = new ListNode();
  l2->val = 9;
  l2->next = new ListNode();
  l2->next->val = 9;

  Solution solution;
  ListNode* result = solution.addTwoNumbers(l1, l2);

  for (ListNode* p = result; p != nullptr; p = p->next) {
    cout << p->val << endl;
  }

  return 0;
}