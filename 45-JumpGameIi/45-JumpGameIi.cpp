// Last updated: 10/27/2025, 7:10:02 PM
class Solution {
public:
    int jump(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        int  l=0,r=0;
        while(r<n-1){
            int maxindex=0;
            for(int i=l;i<=r;i++){
                maxindex=max(maxindex,i+nums[i]);
            }
            l=r+1;
            r=maxindex;
            count++;
        }
        return count;
    }
};