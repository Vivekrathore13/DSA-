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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    //find  critical point distance minimum and max also
    int idx=0;
    int fidx=-1;
    int sidx=-1;
    // use three node but for finding critical points then use c pointer next ka next then 
    // give in while loop condition next ka next !=NULL
    ListNode* a=head;
    ListNode* b=head->next;
    ListNode* c=head->next->next;
    if(c==NULL) return {-1,-1};
    int mind=INT_MAX;
    int f=-1;
    int s=-1;
    while(c){
    if(b->val>a->val && b->val > c->val || b->val < a->val && b->val < c->val )  {
        if(fidx==-1) fidx=idx;// if critical point not find then fidx =idx
        else sidx=idx;// then if find then another critical point update sidx=idx

        f=s;
        s=idx;
        if(f!=-1){
        int d=s-f;
        //find min diatance
        mind=min(mind,d);
        }
    }
    a=a->next;
    b=b->next;
    c=c->next;
    idx++;
    }
    //for find max idx distance 
    if(sidx==-1) return {-1,-1};
    int maxd=sidx-fidx;
    return {mind,maxd};

    }
};