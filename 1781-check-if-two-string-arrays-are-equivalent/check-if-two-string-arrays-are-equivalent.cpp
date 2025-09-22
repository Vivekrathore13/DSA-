class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& s, vector<string>& v) {
    string res="";
    for(auto ele:s){
        res+=ele;
    }   
    string ans="";
    for(auto el:v){
        ans+=el;
    }
    if(ans==res) return true;
    else return false;
    }
};