class Solution {
public:
    vector<int> parent; // har node ka parent store karega
    vector<int> rank;   // rank (height ya size) store karega for union optimization

    // \U0001f539 DSU find operation with path compression
    int find(int i){
        if(parent[i]!=i){                 // agar apna parent khud nahi hai
            parent[i]=find(parent[i]);    // path compression -> upar ke parent se direct connect kar do
        }
        return parent[i];                 // root parent return karo
    }

    // \U0001f539 DSU union operation with rank optimization
    void Union(int x,int y){
        int parx=find(x);   // x ka parent find karo
        int pary=find(y);   // y ka parent find karo

        if(parx!=pary){ // agar dono already same component me nahi hai
            if(rank[parx]>rank[pary]){       // jiski rank jyada hai, wahi parent banega
                parent[pary]=parx;
            }
            else if(rank[parx]<rank[pary]){  // agar dusre ki rank jyada hai
                parent[parx]=pary;
            }
            else{                            // agar rank equal hai
                parent[parx]=pary;           // kisi ko bhi parent bana do (yaha pary ko)
                rank[pary]++;                // jiska parent banaya uski rank badha do
            }
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26); // 26 alphabets ke liye parent array
        rank.resize(26);   // rank array bhi 26 size ka
        for(int i=0;i<26;i++){
            parent[i]=i;   // initially sabka parent khud hi hai
            rank[i]=1;     // sabki rank 1 hai initially
        }   

        // \U0001f539 Step 1: Pehle sabhi "==" wale equations ko union me dal do
        for(string &s:equations){
            if(s[1]=='='){ 
                Union(s[0]-'a',s[3]-'a'); // dono characters ko connect kar do
            }
        }

        // \U0001f539 Step 2: Ab sabhi "!=" wale equations check karo
        for(string &s:equations){
            if(s[1]=='!'){ // agar inequality di hai (a!=b)
                char first=s[0]-'a';   // pehla character index
                char second=s[3]-'a';  // doosra character index
                if (find(first) == find(second)) { 
                    // agar dono ka same parent hai -> contradiction (kyunki equal group me aagaye)
                    return false;
                }
            }
        }

        // agar contradiction nahi mila to equations valid hai
        return true;
    }
};
