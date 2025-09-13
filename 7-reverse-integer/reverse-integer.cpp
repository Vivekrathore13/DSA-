class Solution {
public:
    int reverse(int n) {
    int num=0;
    while(n!=0){
        int dig=n%10;
        if(num>INT_MAX/10 || num<INT_MIN/10){
            return 0;
        }
        num=num*10+dig;
        n=n/10;
    }   
    return num;
    }
};