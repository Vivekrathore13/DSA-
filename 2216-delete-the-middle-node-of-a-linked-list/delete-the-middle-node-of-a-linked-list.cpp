class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr; // 0 or 1 node
    ListNode* temp=head;
    ListNode* first=head;
    int count=0;
    while(temp){
        temp=temp->next;
        count++;
    }

    int m=count/2;
    for(int i=0;i<m-1;i++){
        first=first->next;
    }
    first->next=first->next->next;
    return head;
        
    }
};
