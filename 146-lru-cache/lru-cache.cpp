class LRUCache {
public:
    
    // Doubly Linked List ke liye ek node class banayi gayi hai
    class node{
        public:
            int key,val;
            node* prev;
            node* next;

            // constructor (ek node banane ke liye)
            node(int k,int v){
                key=k;
                val=v;
                prev=next=NULL;
            }
    };

    // Dummy head aur dummy tail node banayi gayi hain (to simplify insertion/deletion)
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);

    // Map use kar rahe hain key -> node pointer store karne ke liye (O(1) access ke liye)
    unordered_map<int,node*> m;

    // Cache ki capacity
    int limit;

    // -------------------------
    // Helper function: ek node ko head ke just baad insert karta hai
    void addnode(node* newnode){
        node* oldnext=head->next;

        head->next=newnode;
        oldnext->prev=newnode;

        newnode->next=oldnext;
        newnode->prev=head;
    }

    // Helper function: ek node ko list se remove karta hai
    void delnode(node* oldnode){
        node* oldperv=oldnode->prev;
        node* oldnext=oldnode->next;

        oldperv->next=oldnext;
        oldnext->prev=oldperv;
    }

    // -------------------------
    // Constructor: cache initialize karne ke liye
    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    // -------------------------
    // get function: agar key present hai to value return karo,
    // aur node ko "most recently used" position (head ke paas) le aao
    int get(int key) {
        if(m.find(key)==m.end()){
            // agar key nahi mili to -1 return
            return -1;
        } 
        node* ansnode=m[key];
        int ans=ansnode->val;

        // purana node hata ke
        m.erase(key);
        delnode(ansnode);

        // use head ke paas dobara insert kar dete hain (MRU banane ke liye)
        addnode(ansnode);
        m[key]=ansnode;

        return ans;
    }
    
    // -------------------------
    // put function: nayi key-value dalna
    void put(int key, int val) {
        // agar key already present hai to purana node delete kar do
        if(m.find(key)!=m.end()){
            node* oldnode=m[key];
            delnode(oldnode);
            m.erase(key);
        }   

        // agar cache full hai to least recently used (tail->prev) ko delete karo
        if(m.size()==limit){
            m.erase(tail->prev->key);
            delnode(tail->prev);
        }

        // ab naya node banao aur head ke paas insert karo
        node* newnode=new node(key,val);
        addnode(newnode);
        m[key]=newnode;
    }
};

/**
 * Usage:
 * LRUCache* obj = new LRUCache(capacity);
 * int val = obj->get(key);
 * obj->put(key,value);
 */
