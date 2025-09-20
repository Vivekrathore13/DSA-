class Solution {
public:
    vector<int> findWordsContaining(vector<string>& s, char x) {
    vector<int> ans;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<s[i].size();j++)
        if(s[i][j]==x){
            ans.push_back(i);
            break;
        }
    } 
    return ans;  
    }
};