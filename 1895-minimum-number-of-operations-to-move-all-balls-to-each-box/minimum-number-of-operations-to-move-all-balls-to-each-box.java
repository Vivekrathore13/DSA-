class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] ans = new int[n];
        
        int moves = 0, balls = 0;
        // Left to right pass
        for (int i = 0; i < n; i++) {
            ans[i] += moves;
            if (boxes.charAt(i) == '1') balls++;
            moves += balls;
        }
        
        moves = 0;
        balls = 0;
        // Right to left pass
        for (int i = n - 1; i >= 0; i--) {
            ans[i] += moves;
            if (boxes.charAt(i) == '1') balls++;
            moves += balls;
        }
        
        return ans;
    }
}
