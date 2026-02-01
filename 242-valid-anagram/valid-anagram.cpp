class Solution {
public:
    bool isAnagram(string s, string t) {
    if(s.length()!=t.length()) return false;
    unordered_map<char,int> mp1;
    for(char ele:s){
        mp1[ele]++;
    }
    for(char ch:t){
        if(mp1.find(ch)!=mp1.end()){
        mp1[ch]--;
        if(mp1[ch]==0) mp1.erase(ch);
       }
    else return false;
    }
    if(mp1.size()==0) return true;
    return false;
    }
};