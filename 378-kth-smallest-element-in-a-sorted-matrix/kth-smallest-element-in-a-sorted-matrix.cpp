class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();
    int ans=0;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        pq.push(matrix[i][j]);
        if(pq.size()>k){ 
        pq.pop();
        }
        }
    }   
    return pq.top(); 
    }
};