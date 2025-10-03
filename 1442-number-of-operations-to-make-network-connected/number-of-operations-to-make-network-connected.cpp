class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    // find
    int find(int i){
        if(parent[i]!=i){
            parent[i]=find(parent[i]);
        }
        return parent[i];
    }
    //union
    void Union(int x,int y){
        int parx=find(x);
        int pary=find(y);

        if(parx!=pary){
            if(rank[parx]>rank[pary]){
                parent[pary]=parx;
            }
            else if(rank[parx]<rank[pary]){
                parent[parx]=pary;
            }
            else {
                parent[parx]=pary;
                rank[pary]++;
            }
        }
    } 
    int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size()<n-1){
        return -1;
    }
    parent.resize(n);
    rank.resize(n,0);   
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int compon=n;
    for(auto &vec:connections){
        if(find(vec[0])!=find(vec[1])){
            Union(vec[0],vec[1]);
            compon--;
        }
    }
    return compon-1;
    }
};