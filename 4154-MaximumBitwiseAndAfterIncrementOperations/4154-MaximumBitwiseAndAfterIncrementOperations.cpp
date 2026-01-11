// Last updated: 1/11/2026, 7:14:26 PM
class Solution {
public:

    int findcost(int ele,int target){
        int y=target;
        for(int i=30;i>=0;i--){
            int xbit=(ele&(1<<i));
            int tbit=(target&(1<<i));
            if(!xbit&&tbit) break;
            if(xbit) y|=xbit;
        }
        return y-ele;
    }
    int maximumAND(vector<int>& nums, int k, int m) {
        int n=nums.size();
        int ans=0;
        for(int bit=30;bit>=0;bit--){
            vector<int>costs;
            for(int i=0;i<n;i++){
                int ele=findcost(nums[i],(ans|(1<<bit)));
                costs.push_back(ele);
            }
            sort(costs.begin(),costs.end());
            long long tcost=0;
            for(int i=0;i<m;i++){
                tcost+=costs[i];
            }
            if(tcost<=k){
                ans|=(1<<bit);
            }
        }
        return ans;
    }
};