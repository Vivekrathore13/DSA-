class Solution {
public:
    bool iscycle(vector<vector<int>>& adj,int u,vector<bool>& visi,vector<bool>& inre){
    visi[u]=true;
    inre[u]=true;

    for(int &v:adj[u]){
         // if not visited then we check for cycle in dfs 

        if(visi[v]==false && iscycle(adj,v,visi,inre))
        return true;
        //agar voh inrecur mai visited hai tho use inrecursion mai 
        else if(inre[v]==true)
        return true;
    }
    inre[u]=false;
    return false;
    }
    bool canFinish(int v, vector<vector<int>>& edges) {
    vector<vector<int>> adj(v);
    for(auto &e:edges){
        int u=e[0];
        int v=e[1];
        adj[v].push_back(u);
    }
    stack<int> st;
    vector<bool> visi(v,false);
    vector<bool> inre(v,false);
    for(int i=0;i<v;i++){
        if(!visi[i] && iscycle(adj,i,visi,inre))
        return false;
    }
    return true;
    }
};