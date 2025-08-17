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
    
    // here is 4 step solution of this code

    //step 1 deep copy

    // deep copy of same linked list using extra dummy node
    Node* dummy= new Node(0);
    Node* tempd=dummy;
    Node* temp=head;
    while(temp!=NULL){
        Node* a= new Node(temp->val);
        tempd->next=a;
        tempd=tempd->next;
        temp=temp->next; 
    }

    //Step 2 Making alternate connection using extra dummy node 

    Node* dupli=dummy->next;
    Node* a=head;
    Node* b=dupli;
    dummy=new Node(-1);// initilize again dummy -1
    Node* tdn=dummy;// it is new temp of dummy node wgich is initilize again with -1
    //main logic of alterante connection
    while(a){
       tdn->next=a;
       a=a->next;
       tdn=tdn->next;
       tdn->next=b;
       b=b->next;
       tdn=tdn->next;
    }
    dummy=dummy->next;

    //Making random connection importent step
    Node* t1=dummy;// t1 traverse the original list 
    while(t1){
        Node* t2=t1->next; // t2 is traverse for duplicate list
        if(t1->random) t2->random=t1->random->next; // making random connection
        t1=t1->next->next;
    }

    // step 4 seperate the list //removing the connection
    //make the two new node to bulid coonection 
    Node* d1=new Node(0);
    Node* d2=new Node(0);
    t1=d1;
    Node* t2=d2;
    Node* t=dummy;
    while(t){
        t1->next=t;
        t=t->next;
        t1=t1->next;
        t2->next=t;
        t=t->next;
        t2=t2->next;
    }
    t1->next=NULL;
    t2->next=NULL;
    d1=d1->next; //original with random 
    d2=d2->next;// duplicate with random
    return d2;
    }
};