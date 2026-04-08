// Last updated: 08/04/2026, 23:54:56
class Solution {
public:
    /*
        one observation is 
        or adds bits everytime and increases its values
        it must equal to maxelement in subarray
        mean the small elements bits must be in a big element in subarray
        if in subarray bits not matched with nay of them the subarray is not valid
        
        i can t use xor tricks 111 11 ->100
        how to do this?

        i cannot do the slidiing window since it is not monotonic

        another observation is or can only add bit every everytime but not decrease
        subarray ending at i the maximum unique values exists are just 30
        
    */
    long long countGoodSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        map<int,int>mp;
        vector<pair<int,int>>cur,next;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
            next.push_back({nums[i],i});
            for(auto [orr,idx]:cur){
                int newval=orr|nums[i];
                if(next.back().first!=newval){
                    next.push_back({newval,idx});
                }
            }
            cur=next;
            next.clear();
            int prev=-1;
            for(int j=cur.size()-1;j>=0;j--){
                auto[val,maxl]=cur[j];
                int eleidx=-1;
                if(mp.find(val)!=mp.end()){
                    eleidx=mp[val];
                }
                int valleft=min(maxl,eleidx);
                if(valleft>prev) ans+=(valleft-prev);
                prev=maxl;
            }

        }
        return ans;
    }
};