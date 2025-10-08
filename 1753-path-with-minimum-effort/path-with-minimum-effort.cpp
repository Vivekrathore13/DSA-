class Solution {
public:
    // Define a pair structure: (effort, (x, y))
    typedef pair<int, pair<int, int>> p;
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        // All 4 possible directions (up, down, left, right)
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        
        // result[x][y] = minimum effort needed to reach (x, y)
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));   
        
        // Lambda function to check if coordinates are inside the matrix
        auto issafe = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < m && y < n;
        };
        
        // Min-heap priority queue → always pick the smallest current effort
        priority_queue<p, vector<p>, greater<p>> pq;
        
        // Starting cell has 0 effort
        result[0][0] = 0;
        pq.push({0, {0, 0}});
        
        // Dijkstra’s algorithm
        while (!pq.empty()) {
            int diff = pq.top().first;              // Current path's effort
            auto cord = pq.top().second;            // Coordinates (x, y)
            pq.pop();
            
            int x = cord.first;
            int y = cord.second;
            
            // Early exit → once we reach bottom-right, return effort
            if (x == m - 1 && y == n - 1) return diff;
            
            // Explore all 4 neighbors
            for (auto &di : dir) {
                int x_ = x + di[0];
                int y_ = y + di[1];
                
                if (issafe(x_, y_)) {
                    // Calculate absolute difference in heights
                    int absdiff = abs(heights[x][y] - heights[x_][y_]);
                    
                    // The effort of reaching neighbor is the max so far
                    int maxdiff = max(diff, absdiff);
                    
                    // If we found a smaller effort path, update it
                    if (result[x_][y_] > maxdiff) {
                        result[x_][y_] = maxdiff;
                        pq.push({maxdiff, {x_, y_}});
                    }
                }
            }
        }
        
        // Final answer: minimum effort to reach bottom-right
        return result[m - 1][n - 1];
        /*
        T.C ->O(m×nlog(m×n))
        S.C->O(m×n)
        */
    }
};
