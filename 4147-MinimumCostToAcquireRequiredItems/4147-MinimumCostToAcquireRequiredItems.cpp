// Last updated: 1/11/2026, 11:09:57 AM
class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costboth, long long need1, long long need2) {
        long long ans=0;
        if(cost1+cost2>costboth){
            long long req=min(need1,need2);
            ans+=1ll*costboth*req;
            need1-=req;
            need2-=req;
        }
        long long ma=max(need1,need2);
        if(1ll*need1*cost1+1ll*need2*cost2>1ll*ma*costboth){
            ans+=1ll*costboth*ma;
            return ans;
        }
        ans+=need1*cost1+need2*cost2;
        return ans;
    }
};