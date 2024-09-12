class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Base cases: if one list is empty, return the other
        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        }

        // Recursive case: compare the current nodes
        if (list1->val <= list2->val) {
            // list1 has the smaller node, so append it to the result and merge the rest
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            // list2 has the smaller node, so append it to the result and merge the rest
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
