class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        // `prev[i]` will store the maximum height to the left of index i
        int prev[n];
        prev[0] = -1;   // No left boundary for the first element
        int max = height[0];
        for (int i = 1; i < n; i++) {
            prev[i] = max;            // Store current max so far (to the left)
            if (max < height[i]) 
                max = height[i];      // Update max if current bar is taller
        }   

        // `next[i]` will store the maximum height to the right of index i
        int next[n];
        next[n - 1] = -1;  // No right boundary for the last element
        max = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            next[i] = max;           // Store current max so far (to the right)
            if (max < height[i]) 
                max = height[i];     // Update max if current bar is taller
        }

        // Reusing `prev` array to store the minimum of left and right max
        // (this represents the water level possible at index i)
        for (int i = 0; i < n; i++) {
            prev[i] = min(prev[i], next[i]);
        }

        // Calculate trapped water
        int water = 0;
        for (int i = 1; i < n - 1; i++) { // First and last elements can't trap water
            if (height[i] < prev[i]) {
                water += (prev[i] - height[i]); // Water trapped is difference between water level and bar height
            }
        }
        
        return water;
    }
};
