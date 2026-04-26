// Last updated: 26/4/2026, 8:05:45 am
1class Solution {
2public:
3    vector<int> findValidElements(vector<int>& nums) {
4        vector<int>ans;
5        ans.push_back(nums[0]);
6        int n=nums.size();
7        for(int i=1;i<n-1;i++){
8            bool a=true;
9            for(int j=0;j<i;j++) if(nums[i]<=nums[j]) {a=false;break;}
10            if(a) ans.push_back(nums[i]);
11            else{
12            a=true;
13            for(int j=i+1;j<n;j++) if(nums[i]<=nums[j]){a=false;break;}
14            if(a) ans.push_back(nums[i]);
15            }
16            
17        }
18        if(n-1!=0) ans.push_back(nums[n-1]);
19        return ans;
20    }
21};