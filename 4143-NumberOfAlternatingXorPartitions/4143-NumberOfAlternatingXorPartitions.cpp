// Last updated: 09/02/2026, 21:05:27
int mod=1e9+7;
class Solution {
public:
    unordered_map<long long,int>dp;
    int findsol(vector<int>&nums,int t1,int t2,int i,int cx,int num){
        if(i==nums.size()){
            if(num==1&&cx==t1) return 1;
            if(num==2&&cx==t2) return 1;
            return 0; 
        }
        // cx^=nums[i];
        auto state = ((long long)i<<32)|((long long)cx<<2)+num;
        if (dp.count(state)) return dp[state];

        int a=0,b=0;
        if(num==1&&cx==t1){
            a=findsol(nums,t1,t2,i+1,nums[i],2);
        }
        if(num==2&&cx==t2){
            a=findsol(nums,t1,t2,i+1,nums[i],1);
        }
        b=findsol(nums,t1,t2,i+1,cx^nums[i],num);
        return dp[state]=(a+b)%mod;
    }
    int alternatingXOR(vector<int>& nums, int t1, int t2) {
        int n=nums.size();
        int num=1;
        return findsol(nums,t1,t2,1,nums[0],num);
    }
};