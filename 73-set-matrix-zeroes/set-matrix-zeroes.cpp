class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
    int m=arr.size();
    int n=arr[0].size();
    vector<bool> row(m,false);
    vector<bool> col(n,false);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 0){
                row[i]=true;
                col[j]=true;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(row[i]== true || col[j]==true){
                arr[i][j]=0;
            }
        }
    }  
    }
};