// Last updated: 1/11/2026, 11:09:58 AM
class Solution {
public:
    long long totalScore(int hp, vector<int>& d, vector<int>& r) {
        int n=d.size();
        vector<long long>p(n+1,0);
        for(int i=1;i<=n;i++){
            p[i]=p[i-1]+d[i-1];
        }
        vector<long long>t(n+1,0);
        for(int i=1;i<=n;i++){
            t[i]=r[i-1]+p[i]-hp;
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            int ip=lower_bound(p.begin(),p.end(),t[i])-p.begin();
            if(ip<=i){
                ans+=i-ip;
            }
        }
        return ans;
    }
};