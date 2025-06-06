class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* secondHalf = reverse(slow->next);

        // Compare both halves
        ListNode* firstHalf = head;
        ListNode* second = secondHalf;
        while (second != nullptr) {
            if (firstHalf->val != second->val) {
                reverse(secondHalf); // Restore list
                return false;
            }
            firstHalf = firstHalf->next;
            second = second->next;
        }

        reverse(secondHalf); // Restore list
        return true;
    }
};
