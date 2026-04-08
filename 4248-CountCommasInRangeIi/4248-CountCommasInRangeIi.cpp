// Last updated: 08/04/2026, 23:54:42
class Solution {
public:
    long long countCommas(long long n) {
        long long d=(n%3==0)?(n/3-1):n/3;
        long long c=0;
        long long k=1000;
        // if(n==k) return 
        while(k<=n){
            long long r=min(k*10-1,n);
            string s=to_string(r);
            d=(s.size()%3==0)?(s.size()/3-1):s.size()/3;
            cout<<d<<endl;
            c+=d*(r-k+1);
            k*=10;
        }
        return c;
    }
};