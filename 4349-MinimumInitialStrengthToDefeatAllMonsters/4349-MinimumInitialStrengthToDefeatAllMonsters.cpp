// Last updated: 19/8/2026, 11:58:10 pm

class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        vector<long long>bns(n,0);
        for(auto &it:boosts){
            bns[it[0]]+=it[2];
            if(it[1]+1<n) bns[it[1]+1]-=it[2];
        }
        for(int i=1;i<n;i++){
            bns[i]+=bns[i-1];
        }
        // for(auto it:bns){
        //     cout<<it<<" ";
        // }
        long long ans=0;
        int i=n-1;
        while(i>=0&&bns[i]>=monsters[i]){
            i--;
        }
        if(i>=0){
            ans+=monsters[i]-bns[i];
            i--;
        }
        while(i>=0){
            ans+=monsters[i];
            i--;
        }
        return ans;
    }
};