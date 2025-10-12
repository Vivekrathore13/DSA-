class Solution {
public:
    string makeGood(string s) {
    int n=s.length();
    string ans="";  
   for(char &ch:s){
    if(!ans.empty() && (ans.back() + 32 == ch || ans.back() - 32 == ch)){
        ans.pop_back();
    } else{
        ans.push_back(ch);
    }
   }
   return ans;
    }
};