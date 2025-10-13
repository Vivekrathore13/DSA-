class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int n=nums.size();
    //step 1 find pivot idx
    int idx=-1;
    for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
        idx=i;
        break;
        }
    }   
    //reverse if array is already sorted
    if(idx==-1){
        reverse(nums.begin(),nums.end());
        return;
    }
    //step 3
    reverse(nums.begin()+idx+1,nums.end());

    //step 4 find greatest for some test cases

    int j=-1;
    for(int i=idx+1;i<n;i++){
        if(nums[i]>nums[idx]){
            j=i;
            break;
        }
       }
       //swap step 5 
       int temp=nums[idx];
       nums[idx]=nums[j];
       nums[j]=temp;
       return;
    }
};