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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> numSet(nums.begin(), nums.end());

        // Create a dummy node to simplify removal of head if necessary
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Pointer to track the previous node
        ListNode* prev = dummy;

        // Traverse the list
        while (head != nullptr) {
            if (numSet.find(head->val) != numSet.end()) {
                // If the current node's value exists in nums, remove the node
                prev->next = head->next;
            } else {
                // Otherwise, move the prev pointer forward
                prev = head;
            }
            head = head->next;
        }

        // Return the modified list, which starts from dummy->next
        return dummy->next;
    }
};