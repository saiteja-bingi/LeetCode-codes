// Last updated: 09/02/2026, 21:05:20
class Solution {
public:
    int minimumK(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        sort(nums.begin(),nums.end());
        int ans=-1;
        int m=*max_element(nums.begin(),nums.end());
        for(int i=1;i<=100000;i++){
            int ele=i;
            int op=0;
            for(int i=0;i<n;i++){
                op+=(nums[i]+ele-1)/ele;
                if(op>ele*ele) break;
                // if(o)
            }
            if(op<=ele*ele) return ele;
        }
        return -1;
    }
};