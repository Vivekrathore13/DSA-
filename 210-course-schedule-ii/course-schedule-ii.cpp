class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& edges) {
      vector<vector<int>> adj(v);
        for(auto &e : edges){
            int u=e[1];
            int v=e[0];
            adj[u].push_back(v);
        }
        vector<int> indeg(v,0);
        queue<int> que;
        
        for(int u=0;u<v;u++){
            for(int &v:adj[u]){
                 indeg[v]++;
            }
        }
        //fill indegree with 0;
        for(int i=0;i<v;i++){
            if(indeg[i]==0){
                que.push(i);
            }
        }
        //simple bfs
        vector<int> res;
        while(!que.empty()){
            int u=que.front();
            res.push_back(u);
            que.pop();
            
            for(int &v:adj[u]){
                indeg[v]--;
                if(indeg[v]==0){
                    que.push(v);
                }
            }
        }
        // if cycle exist
        if(res.size()!=v) return {};
        return res;   
    }
};