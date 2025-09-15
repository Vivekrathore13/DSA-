class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    int n=arr.size();
    vector<vector<int>> v;
    int mindif=INT_MAX;
    for(int i=0;i<n-1;i++){
        int dif=arr[i+1]-arr[i];
         mindif=min(mindif,dif);
    }   
    for(int i=0;i<n-1;i++){
        if(arr[i+1]-arr[i]==mindif){
            v.push_back({arr[i],arr[i+1]});
        }
    }
    return v;
    }
};