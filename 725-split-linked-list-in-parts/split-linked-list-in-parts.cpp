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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
    //finding the original size of linked list 
    int n=0;
    ListNode* temp=head;
    while(temp){
        temp=temp->next;
        n++;
    }    
    //breaking the list int o k lists
    //aproach is using farzi node make a list of vector return head of every list and head in vector push back all list of head
    vector<ListNode*> ans;
    int size=n/k;
    int rem=n%k; // it is imp beacuse it says how the list break in n/k+1 size it is count of how the size is starting 
    temp=head;
    while(temp){
    ListNode* c=new ListNode(100);
    ListNode* tempc=c;
    int s=size;
    if(rem>0) s++;
    rem--;
    for(int i=1;i<=s;i++){
        tempc->next=temp;
        temp=temp->next;
        tempc=tempc->next;
    }  
    // after the first list is complete then make null last node;
    tempc->next=NULL;
    ans.push_back(c->next);
    }
    // edge case if actual size is less then k then fill null 
    if(ans.size()<k){
        int extra=k-ans.size();
        for(int i=1;i<=extra;i++){
            ans.push_back(NULL);
        }
    }
    return ans;
    }
};