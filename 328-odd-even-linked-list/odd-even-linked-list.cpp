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
    ListNode* oddEvenList(ListNode* head) {
    ListNode* lo=new ListNode(100);
    ListNode* templo=lo;
    ListNode* hi=new ListNode(200);
    ListNode* temphi=hi;
    ListNode* temp=head;
    int pos=1;
    while(temp!=NULL){
        if(pos%2!=0){ //odd list
            templo->next=temp;
            temp=temp->next;
            templo=templo->next;
        }
        else{
            temphi->next=temp;
            temp=temp->next;
            temphi=temphi->next;
        }
        pos++;
    }
    templo->next=hi->next;
    temphi->next=NULL;
    return lo->next;    
    }
};