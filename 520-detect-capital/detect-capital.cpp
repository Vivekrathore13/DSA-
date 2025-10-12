class Solution {
public:
bool allcapi(string s){
    for(char &ch:s){
        if(ch<'A' || ch>'Z')
            return false;
        }
        return true;
    }
    bool allsmall(string s){
    for(char &ch:s){
        if(ch<'a' || ch>'z')
            return false;
    }
    return true;
}
    bool detectCapitalUse(string s) {
   if(allcapi(s) || allsmall(s) || allsmall(s.substr(1))){
    return true;
   }
   return false;
    }
};