class Solution {
public:
    typedef pair<int,int> p;
    int minmst(vector<vector<p>>& adj,int n){
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,0}); // weight,vertex
        vector<bool> inmst(n,false);

        int sum=0;

        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();

            int wt=p.first;
            int node=p.second;

            if(inmst[node]==true)
            continue;

            inmst[node]=true;
            sum+=wt;

            for(auto &tm:adj[node]){
                int neigh=tm.first;
                int neight_wt=tm.second;

                if(inmst[neigh]==false){
                    pq.push({neight_wt,neigh});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
       int n=points.size();
       vector<vector<p>> adj(n);
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j<n; j++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
                    
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    
                    int d = abs(x1-x2) + abs(y1-y2);
                    
                    adj[i].push_back({j, d});
                    adj[j].push_back({i, d});
                }
            }
            return minmst(adj, n);
    }
};