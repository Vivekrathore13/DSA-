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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* temp=head;
    int count=0;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }   
     if(n == count){
            return head->next;
        }
    int m=count-n+1;
    int nth=m-1;
    temp=head;
    for(int i=1;i<=nth-1;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return head;
    }
};