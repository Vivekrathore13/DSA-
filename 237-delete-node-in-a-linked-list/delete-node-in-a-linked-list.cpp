/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* tar) {
    // in this question is tricky because we are not deleting the ndoe delete the value so the it becomes

     // 10,20 ,30 ,40 ,50 =>tar =30 
     // so tho 30 ko 40 bana do dur 40 ko 50 bus 

     // so the code is 

     tar->val=tar->next->val;
     tar->next=tar->next->next; 
    }
};