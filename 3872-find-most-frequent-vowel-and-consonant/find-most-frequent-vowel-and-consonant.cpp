class Solution {
public:
bool isvowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
    return false;
}
    int maxFreqSum(string s) {
    unordered_map<char,int> mp;
    for(int ele:s){
        mp[ele]++;
    }  
    int maxvowel=0;
    int maxcons=0;

    for(auto el:mp){
        if(isvowel(el.first)) maxvowel=max(maxvowel,el.second);
        else maxcons=max(maxcons,el.second);
    }
    return maxcons+maxvowel;
    }
};