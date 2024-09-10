/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* insertGreatestCommonDivisors(ListNode* head) {
    for (ListNode* curr = head; curr->next != nullptr;) {
      ListNode* inserted =
          new ListNode(__gcd(curr->val, curr->next->val), curr->next);
      curr->next = inserted;
      curr = inserted->next;
    }
    return head;
  }
};