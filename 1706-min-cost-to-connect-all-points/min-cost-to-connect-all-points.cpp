class Solution {
public:
    typedef pair<int, int> p; // pair: {weight, node}

    // \U0001f9e9 Helper function to find MST cost using Prim's Algorithm
    int minmst(vector<vector<p>>& adj, int n) {
        // Min-heap (priority queue) -> stores {weight, vertex}
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 0}); // start with vertex 0 and cost 0

        vector<bool> inMST(n, false); // track nodes included in MST
        int sum = 0; // store total weight of MST

        // Standard Prim’s algorithm loop
        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            // Skip if node is already in MST
            if (inMST[node]) continue;

            // Include current node in MST
            inMST[node] = true;
            sum += wt;

            // Traverse all adjacent edges
            for (auto &tm : adj[node]) {
                int neigh = tm.first;
                int neigh_wt = tm.second;

                // Only consider neighbors not yet in MST
                if (!inMST[neigh]) {
                    pq.push({neigh_wt, neigh});
                }
            }
        }
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        /*
        -----------------------------------------------------------------
        \U0001f9e0 Problem:
        Given N points on a 2D plane, connect all points such that the total
        cost is minimum. The cost between two points is the Manhattan distance:
        |x1 - x2| + |y1 - y2|.

        \U0001f9e9 Approach:
        1️⃣ Build a fully connected weighted graph (adjacency list),
            where each edge weight = Manhattan distance between two points.
        2️⃣ Run Prim’s algorithm to compute the Minimum Spanning Tree (MST).
        3️⃣ Return the total weight (sum of MST edges).

        ---------------------------------------------------------------
        ⏱️ Time Complexity:
             Building adjacency list: O(N²)
             Prim’s algorithm:        O(E log V) ≈ O(N² log N)
             ➤ Total: O(N² log N)

        \U0001f4be Space Complexity:
             Adjacency list: O(N²)
             Priority queue & visited arrays: O(N)
             ➤ Total: O(N²)

        -----------------------------------------------------------------
        */
        
        int n = points.size();
        vector<vector<p>> adj(n); // adjacency list: adj[node] = {neighbor, weight}

        // Step 1: Build the adjacency list using Manhattan distance
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x1 - x2) + abs(y1 - y2); // Manhattan distance

                // Since undirected graph, add both directions
                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        // Step 2: Call Prim's helper function to find MST cost
        return minmst(adj, n);
    }
};
