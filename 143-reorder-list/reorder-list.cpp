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
    ListNode* curr=head;
    ListNode* prev=NULL;
    ListNode* next=NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }  
    return prev;
    }
    void reorderList(ListNode* head) {
    // left middle aa gaya ise
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* b=reverseList(slow->next);
    ListNode* a=head;
    slow->next=NULL;
    //merge the a and b using third dummy node in alternate way 
    //dummy node
    ListNode* c=new ListNode(0);
    ListNode* tempa=a;
    ListNode* tempb=b;
    ListNode* tempc=c;

    //main logic of reorder to merge in alternate way 

    while(tempa && tempb){
        tempc->next=tempa;
        tempa=tempa->next;
        tempc=tempc->next;

        tempc->next=tempb;
        tempb=tempb->next;
        tempc=tempc->next;
    }
    //handle edge case
    tempc->next=tempa;
    head=c->next;
    }
};