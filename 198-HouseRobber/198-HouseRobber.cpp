// Last updated: 10/27/2025, 7:08:45 PM
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int fir=nums[i];
            if(i>1){
                fir+=prev2;
            }
            int sec=prev;
            int curr=max(fir,sec);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};