// Last updated: 10/27/2025, 7:23:04 PM
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend==divisor) return 1;
        bool sign=true;
        if(dividend<0&&divisor>0) sign=false;
        else if(dividend>0&&divisor<0) sign=false;
        
        long n=labs(dividend);
        long d=labs(divisor);
        long ans=0;
        
        while(n>=d){
            long temp=d;
            long count=1;
            while(n>=(temp<<1)){
                temp<<=1;
                count<<=1;
            }
            ans+=count;
            n-=temp;
        }

        if(!sign) return -ans;
        return ans;
    }
};