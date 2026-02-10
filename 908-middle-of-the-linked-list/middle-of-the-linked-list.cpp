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
    ListNode* middleNode(ListNode* head) {
    // there are two method two solve first is o(n^2)

    int count =0;
    ListNode* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }  
    int midi=count/2;
    ListNode* mid=head;
    for(int i=1;i<=midi;i++){
        mid=mid->next;
    }
    return mid;
    }
};