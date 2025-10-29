class Solution {
    public int smallestNumber(int n) {
        int k = 1;
        int val = (1 << k) - 1;
        
        while (val < n) {
            k++;
            val = (1 << k) - 1;
        }
        
        return val;
    }
}
