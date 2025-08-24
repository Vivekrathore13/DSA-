class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int n=nums.size();
    int i=0;
    int j=0;
    int k=1;
    int maxlen=INT_MIN,len=INT_MIN,flip=0;
    while(j<n){
        // jab nums 1 hai
        if(nums[j]==1) j++;
        else{
            //jab flip k se chote ho tab 
            if(flip<k){
                flip++;
                j++;
            }
            //jab flip khatm ho jaye tho hume i ko first zero ke age lekar anaa hai
            else{
                len=j-i;
                maxlen= max(maxlen,len);
                while(nums[i]==1) i++;
                    i++;
                    j++;
            }
        }
        // ho sakta hai last window answer ho tho
    }  
        len=j-i;
        maxlen= max(maxlen,len); 
    return maxlen-1;    
    }
};