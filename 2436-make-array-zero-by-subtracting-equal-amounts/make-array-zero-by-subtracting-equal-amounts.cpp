class Solution {
public:
    int minimumOperations(vector<int>& arr) {
        unordered_set<int> mp;
        
        for (int ele : arr) {
            if (ele > 0) {       
                mp.insert(ele);  
            }
        }
        
        return mp.size(); 
    }
};
