// Last updated: 19/8/2026, 11:58:22 pm
#define ll long long
class Solution {
public:
    int kthDigit(long long k) {
        if(k<=9) return k;
        k-=9;
        ll d=2;
        while(1){
            ll bc=9;
            for(int i=0;i<d-2;i++) bc*=10;
            if(k<=bc*10*d) break;
            k-=bc*10*d;
            d++;
        }
        k--;
        ll idx=(k)/(10*d);
        ll r=(k)%(10*d);
        ll act=1;
        for(int i=0;i<d-2;i++) act*=10;
        act+=idx;
        ll num;
        if(act%2==0) num=10*act+r/d;
        else num=10*act+9-r/d;

        string ans=to_string(num);
        return ans[r%d]-'0';
    }
};