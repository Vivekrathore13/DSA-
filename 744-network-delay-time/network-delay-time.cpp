class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // STEP 1️⃣: Create adjacency list with pairs {neighbor, weight}
        // Use 1-based indexing as nodes are 1..n
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &vec : times) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            // Add edge u -> v with weight w
            adj[u].push_back({v, w});
        }

        // STEP 2️⃣: Min-heap to always pick node with smallest distance
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // STEP 3️⃣: Distance array (1-based)
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        pq.push({0, k}); // {distance, node}

        // STEP 4️⃣: Dijkstra's algorithm
        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &it : adj[node]) {
                int adjNode = it.first;   // neighbor node
                int wt      = it.second;  // edge weight

                // Relaxation step
                if(d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // STEP 5️⃣: Find the maximum distance
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++)
            ans = max(ans, dist[i]);

        // STEP 6️⃣: If any node is unreachable, return -1
        return ans == INT_MAX ? -1 : ans;
    }
};
