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
    ListNode* reverseList(ListNode* head) {
    // code of reverse list using recursion
    if(head==NULL || head->next==NULL) return head;
    ListNode* newhead = reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
    }
    bool isPalindrome(ListNode* head) {
     ListNode* slow=head;
      ListNode* fast=head;

      //finding left middile
      while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
      }
      //create two pointer variable for compare the value
      ListNode* new1=reverseList(slow->next);
      ListNode* a=head;
      ListNode* b=new1;
      // Actual loop to check the value 
      while(b){
        if(a->val != b->val) return false;
        a=a->next;
        b=b->next;
      }
      return true;
    }
};