class Solution {
public:
    bool isAnagram(string s, string t) {
    if(s.length()!=t.length()) return false;
    unordered_map<char,int> mp;

    for(int ele:s){
        mp[ele]++;
    }  
    for(auto el:t){
        if(mp.find(el)!=mp.end()){
            mp[el]--;
        if(mp[el]==0) mp.erase(el);
        }
        else return false;
    
    }
    if(mp.size()==0) return true;
    return false;
    }
};