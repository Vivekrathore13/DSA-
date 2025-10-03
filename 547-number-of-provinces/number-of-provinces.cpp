class Solution {
public:
    void dfs(vector<vector<int>>& adj,int u,vector<bool>& visi){
        visi[u]=true;

        //visit neighbours
        for(int &v:adj[u]){
            if(!visi[v]){
                dfs(adj,v,visi);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }
    vector<bool> visi(n,false);
    int count=0;
    for(int i=0;i<n;i++){
        if(!visi[i]){
            count++;
            dfs(adj,i,visi);
        }
    }
    return count;
    }
};