class Solution {
public:
    int unequalTriplets(vector<int>& arr) {
    int n=arr.size();
    int count=0;   
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i] != arr[j] && arr[i] != arr[k] && arr[j] != arr[k]){
            count++;
            }
        }
        
        }
    } 
    return count;    
    }
};