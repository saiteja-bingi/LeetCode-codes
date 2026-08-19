// Last updated: 19/8/2026, 11:58:43 pm
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp(1e5+2,-1);
        int n=nums.size();
        if(nums[0]==1) return n;
        for(int i=0;i<n;i++){
            if(temp[nums[i]]==-1){
                int j=1;
                while(j <= 100000 / nums[i]){
                    if(temp[j*nums[i]]==-1) temp[j * nums[i]] = nums[i];
                    j++;
                }
            }
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=temp[nums[i]];
        }
        return sum;
    }
};