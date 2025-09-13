class Solution {
public:
    int countPrimes(int n) {
    vector<bool> count(n+1,true);
    int cou=0;
    for(int i=2;i<n;i++){
        if(count[i]){
            cou++;
        }
        for(int j=i*2;j<n;j=j+i){
            count[j]=false;
        }
    }   
    return cou; 
    }
};