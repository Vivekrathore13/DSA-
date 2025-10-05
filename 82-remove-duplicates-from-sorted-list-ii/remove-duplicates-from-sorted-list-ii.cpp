class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode dummy(0, head); // to handle head duplicates
        ListNode* a = &dummy;    // points to last confirmed unique node
        ListNode* b = head;      // scanning pointer

        while (b != nullptr) {
            bool duplicate = false;

            // Move b forward while the next node has the same value
            while (b->next != nullptr && b->val == b->next->val) {
                duplicate = true;
                b = b->next;
            }

            if (duplicate) {
                // Skip all duplicates
                a->next = b->next;
            } else {
                // No duplicates — move a forward
                a = a->next;
            }

            b = b->next;
        }

        return dummy.next;
    }
};
