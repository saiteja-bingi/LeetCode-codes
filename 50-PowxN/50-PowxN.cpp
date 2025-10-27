// Last updated: 10/27/2025, 7:09:58 PM
class Solution {
public:
    double myPow(double x, int n) {
        long long exp=n;
        if(exp<0){
            x=1/x;
            exp=-exp;
        }
        double ans=1;
        while(exp>0){
            if(exp%2==0){
                x*=x;
                exp/=2;
            }
            else{
                ans*=x;
                x*=x;
                exp/=2;
            }
        }
        return ans;
    }
};