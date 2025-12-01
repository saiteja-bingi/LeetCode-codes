// Last updated: 12/1/2025, 7:13:19 PM
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int count=0;
        int n=nums.size();
        vector<int>pre(n);
        pre[0]=((nums[0]==target)?1:0);
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+((nums[i]==target)?1:0);
        }
        // for(auto it:pre) cout<<it<<" ";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int total;
                if(i-1>=0) {total=pre[j]-pre[i-1];}
                else {total=pre[j];}
                if(total>((j-i+1)/2)) count++;
            }
        }
        return count;
    }
};