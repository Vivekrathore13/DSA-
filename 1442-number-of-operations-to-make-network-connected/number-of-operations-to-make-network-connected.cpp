class Solution {
public:
    vector<int> parent; // parent[i] -> representative (root) of set i
    vector<int> rank;   // rank[i] -> tree height approximation for union optimization

    // \U0001f539 FIND operation (with path compression)
    int find(int i){
        if(parent[i]!=i){          // agar root nahi hai
            parent[i]=find(parent[i]); // recursively root find karo, aur path compress karo
        }
        return parent[i];          // root return karo
    }
    // ⏳ TC: O(α(n)) ≈ O(1) (amortized)  
    // \U0001f4be SC: O(1) (recursion stack negligible)

    // \U0001f539 UNION operation (union by rank)
    void Union(int x,int y){
        int parx=find(x);          // x ka root
        int pary=find(y);          // y ka root

        if(parx!=pary){            // dono alag set me hai
            if(rank[parx]>rank[pary]){  // jiski rank zyada hai, vo root banega
                parent[pary]=parx;
            }
            else if(rank[parx]<rank[pary]){
                parent[parx]=pary;
            }
            else {                 // equal rank case -> koi bhi root banado
                parent[parx]=pary;
                rank[pary]++;      // rank badha do
            }
        }
    }
    // ⏳ TC: O(α(n)) ≈ O(1) (amortized)  
    // \U0001f4be SC: O(1)

    // \U0001f539 Main function: makeConnected
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Agar edges < n-1 -> graph ko connect karna impossible
        if(connections.size()<n-1){
            return -1;
        }

        // DSU initialization
        parent.resize(n);          // sabke liye parent bana diya
        rank.resize(n,0);          // initial rank = 0
        for(int i=0;i<n;i++){
            parent[i]=i;           // initially har node apna khud root hai
        }

        int compon=n;              // initially har node alag component hai

        // Process all connections (edges)
        for(auto &vec:connections){
            // agar dono already same component me nahi hai -> union karo
            if(find(vec[0])!=find(vec[1])){
                Union(vec[0],vec[1]);
                compon--;          // ek component kam ho gaya
            }
        }

        // answer = kitne extra operations required = total components - 1
        return compon-1;
    }
    // ⏳ TC:
    //   - Initialization: O(n)
    //   - Processing edges: O(E * α(n)) ≈ O(E)
    //   - Overall: O(n + E)
    // \U0001f4be SC: O(n) (parent + rank arrays)
};
