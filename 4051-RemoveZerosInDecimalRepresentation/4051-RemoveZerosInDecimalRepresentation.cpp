// Last updated: 10/27/2025, 7:04:57 PM
class Solution {
public:
    long long removeZeros(long long n) {
        long long num=0;
        long long k=1;
        while(n>0){
            long long r=n%10;
            if(r==0){
                n/=10;
                continue;
            }
            num=num+k*r;
            k=k*10;
            n/=10;
        }
        return num;
    }
};