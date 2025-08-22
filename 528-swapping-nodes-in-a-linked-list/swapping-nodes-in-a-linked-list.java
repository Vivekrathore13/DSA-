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
    public ListNode swapNodes(ListNode head, int k) {
     ListNode temp = head;
        ListNode first = head;
        ListNode second = head;
        int count = 0;
        
        // Count total nodes
        while (temp != null) {
            count++;
            temp = temp.next;
        }
        
        // Move first to kth node from start
        for (int i = 1; i < k; i++) {
            first = first.next;
        }
        
        // Move second to kth node from end
        for (int i = 1; i < count - k + 1; i++) {
            second = second.next;
        }
        
        // Swap values
        int t = first.val;
        first.val = second.val;
        second.val = t;
        
        return head;    
    }
}


 // c++ code


/*ListNode* temp =head;
    ListNode* first=head;
    ListNode* second=head;
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
      for(int i=1;i<k;i++){
        first=first->next;
      }

      for(int i=1;i<count-k+1;i++){
        second=second->next;
      }

      swap(first->val,second->val);
      return head;
      */