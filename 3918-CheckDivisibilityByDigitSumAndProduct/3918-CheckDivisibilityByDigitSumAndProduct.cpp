// Last updated: 10/27/2025, 7:05:01 PM
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,product=1;
        int num=n;
        while(n>0){
            int rem=n%10;
            sum+=rem;
            product*=rem;
            n=n/10;
        }
        if(num%(sum+product)==0) return true;
        else return false;
    }
};