class Solution {
public:
    typedef pair<int,int> p; // pair: {row, col}
    
    // 4 directions: up, right, down, left
    vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};
    
    int orangesRotting(vector<vector<int>>& grid) {
        /*
        -----------------------------------------------------------------
        \U0001f9e9 Problem:
        Given a grid with:
        0 = empty cell
        1 = fresh orange
        2 = rotten orange
        Every minute, rotten oranges rot adjacent fresh oranges.
        Find minimum minutes until no fresh orange remains.

        ---------------------------------------------------------------
        ⏱️ Time Complexity:
             O(m * n)  — each cell is visited at most once.

        \U0001f4be Space Complexity:
             O(m * n)  — queue may store all rotten oranges at once.

        -----------------------------------------------------------------
        */

        int m = grid.size();
        int n = grid[0].size();
        queue<p> qu;
        int freshOrange = 0;

        // Step 1: Add all initial rotten oranges to the queue
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    qu.push({i,j});
                } else if(grid[i][j] == 1){
                    freshOrange++;
                }
            }
        }

        // If no fresh oranges, return 0
        if(freshOrange == 0) return 0;

        // Helper lambda to check if a cell is valid and has a fresh orange
        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1;
        };

        int minute = 0;

        // Step 2: BFS
        while(!qu.empty()){
            int size = qu.size();
            bool rottedThisMinute = false;

            for(int i = 0; i < size; i++){
                auto curr = qu.front();
                qu.pop();
                int r = curr.first;
                int c = curr.second;

                // Check all 4 directions
                for(auto &d : dir){
                    int newR = r + d[0];
                    int newC = c + d[1];

                    if(isSafe(newR, newC)){
                        grid[newR][newC] = 2; // rot the fresh orange
                        qu.push({newR, newC});
                        freshOrange--;
                        rottedThisMinute = true;
                    }
                }
            }

            if(rottedThisMinute) minute++;
        }

        // If any fresh orange remains, return -1; otherwise return minutes
        return (freshOrange == 0) ? minute : -1;
    }
};
