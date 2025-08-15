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
    ListNode* mergeInBetween(ListNode* head, int a, int b, ListNode* head2) {
    int n=0;
    ListNode* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        n++;
    } 
    // marak all position
    ListNode* first=head;
    for(int i=1;i<a;i++){
        first=first->next;
    }

    ListNode* sec=head;
    for(int i=1;i<b+2;i++){
         sec=sec->next;
    } 
    first->next=head2;
    ListNode* temp2=head2;

    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=sec;
    return head;
    }
};