class Solution {
public:
    bool halvesAreAlike(string s) {
    int n=s.length();
    int mid=n/2;
    int i=0;
    int j=mid;
    int counti=0;
    int countj=0;
    while(i<n/2 && j<n){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            counti++;
        }
        if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='A' || s[j]=='E' || s[j]=='I' || s[j]=='O' || s[j]=='U'){
            countj++;
        }
        i++;
        j++;
    }
    return counti==countj;    
    }
};