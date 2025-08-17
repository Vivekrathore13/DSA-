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
    ListNode* swapPairs(ListNode* head) {
        //base case
    if(head==NULL || head->next==NULL){
        return head;
    }    
    // making a three pointer and update the pointer and swap the connection
    ListNode* first=head;
    ListNode* sec=head->next;
    ListNode* prev=NULL;
    while(first && sec){
        // making a third pointer to store the next connection
       ListNode*third=sec->next;
       sec->next=first;
       first->next=third;
       if(prev){
       prev->next=sec;
       } else {
        head=sec;
       }
       // update for second iteration 
       prev=first;
       first=third;
       if(third){
       sec=third->next;
       }
       else{
        sec=NULL;
       }
    }
    return head;
    }
};