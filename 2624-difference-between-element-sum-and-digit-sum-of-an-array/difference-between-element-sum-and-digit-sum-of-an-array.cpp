class Solution {
public:
int digit(vector<int> arr){
    int sum=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
    int digi=arr[i];
    while(digi>0){
        sum+=digi%10;
        digi/=10;
    }
    }
    return sum;
}
    int differenceOfSum(vector<int>& nums) {
    int n=nums.size();
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=nums[i];
    }   
    return abs(ans-digit(nums));
    }
};