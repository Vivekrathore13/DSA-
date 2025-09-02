class Solution {
public:
    vector<int> findPeaks(vector<int>& arr) {
    vector<int> ans;
    int n=arr.size();
    for(int i=1;i<n-1;i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            ans.push_back(i);
        }
    }
    return ans;
    }
};