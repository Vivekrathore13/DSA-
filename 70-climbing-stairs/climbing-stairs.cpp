class Solution {
public:
    int ans(int n){
       if (n <= 2) return n;
        int a = 1, b = 2, c;
        for(int i = 3; i <= n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
    int climbStairs(int n) {
    return ans(n); 
    }
};
//T.C is o(n); and space is o(1);