// Last updated: 15/8/2026, 9:02:28 pm
1#define ll long long
2class Solution {
3public:
4    int kthDigit(long long k) {
5        if(k<=9) return k;
6        k-=9;
7        ll d=2;
8        while(1){
9            ll bc=9;
10            for(int i=0;i<d-2;i++) bc*=10;
11            if(k<=bc*10*d) break;
12            k-=bc*10*d;
13            d++;
14        }
15        k--;
16        ll idx=(k)/(10*d);
17        ll r=(k)%(10*d);
18        ll act=1;
19        for(int i=0;i<d-2;i++) act*=10;
20        act+=idx;
21        ll num;
22        if(act%2==0) num=10*act+r/d;
23        else num=10*act+9-r/d;
24
25        string ans=to_string(num);
26        return ans[r%d]-'0';
27    }
28};