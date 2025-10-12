class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n = arr.size();

        // Step 1: Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(arr[i][j], arr[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(arr[i].begin(), arr[i].end());
        }
    }
};
