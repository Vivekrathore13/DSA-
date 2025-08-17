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
    ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp=head;
    int count=0;
    //check if k nodes exist
    while(count<k){
       if(temp==NULL) return head;
       temp=temp->next;
       count++;
    }
      // recursively call rest of the linked list
      ListNode* previous= reverseKGroup(temp,k);

      //reverse current group
      temp=head;
      count=0;
      while(count<k){
        ListNode* next=temp->next;
        temp->next=previous;
        previous=temp;
        temp=next;
        count++;
      }
      return previous;
    }
};