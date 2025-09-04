class Solution {
public:
    int findClosest(int x, int y, int z) {
    int n=abs(z-x);
    int m=abs(z-y);
    if(n<m) return 1;
    else if(m<n) return 2;
    else return 0;    
    }
};