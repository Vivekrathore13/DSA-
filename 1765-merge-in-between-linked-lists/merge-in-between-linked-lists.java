/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeInBetween(ListNode head1, int a, int b, ListNode head2) {
        ListNode first = head1;
        ListNode second = head1;

        // Comment dal diye hai 

        
        // Move first to node just before index a
        for (int i = 0; i < a - 1; i++) {
            first = first.next;
        }

        // Move second to node at index b
        for (int i = 0; i < b; i++) {
            second = second.next;
        }

        // Connect first.next to head2
        first.next = head2;

        // Find tail of head2
        ListNode tail = head2;
        while (tail.next != null) {
            tail = tail.next;
        }

        // Connect tail.next to second.next
        tail.next = second.next;

        return head1;
    }
}
