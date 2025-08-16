/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    // STEP 1 -> CREATE THE DEEP COPY WITHOUT RANDOM POINTER
    Node* dummy=new Node(0);
    Node* tempC=dummy;
    Node* temp=head;
    while(temp){
        Node* a = new Node(temp->val);
        tempC->next=a;
        tempC=tempC->next;
        temp=temp->next;
    }
    Node* b = dummy->next;
    Node* a = head;
    //STEP 2 MAKE A MAP OF ORIGINAL AND DUPLICATE
    unordered_map<Node*,Node*> m;
    Node* tempa = a;
    Node* tempb = b;
    while(tempa!=NULL){
        m[tempa]=tempb;
        tempa=tempa->next;
        tempb=tempb->next;
    }
    for(auto x : m){
        Node* o=x.first;
        Node* d=x.second;
        if(o->random!=NULL){
            //kaam karo
            Node* orandom= o->random;
            Node* drandom= m[o->random];
            d->random= drandom;
        }
    }
    return b;
 }
};