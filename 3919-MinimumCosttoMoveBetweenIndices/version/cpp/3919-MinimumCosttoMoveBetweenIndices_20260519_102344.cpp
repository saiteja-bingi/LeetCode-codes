// Last updated: 19/5/2026, 10:23:44 am
1class Solution {
2public:
3    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
4        int n=nums.size();
5        vector<int>close(n,0);
6        close[0]=1;close[n-1]=n-2;
7        for(int i=1;i<n-1;i++){
8            if(abs(nums[i]-nums[i-1])<=abs(nums[i]-nums[i+1])){
9                close[i]=i-1;
10            }
11            else close[i]=i+1;
12        }
13        vector<int>left(n,0),right(n,0);
14        for(int i=1;i<n;i++){
15            left[i]=left[i-1]+((close[i]<i)?1:abs(nums[i]-nums[i-1]));
16        }
17        for(int i=n-2;i>=0;i--){
18            right[i]=right[i+1]+((close[i]>i)?1:abs(nums[i]-nums[i+1]));
19        }
20        vector<int>ans;
21        for(auto q:queries){
22            int l=q[0],r=q[1];
23            if(l<r){
24                ans.push_back(right[l]-right[r]);
25            }
26            else ans.push_back(left[l]-left[r]);
27        }
28        return ans;
29    }
30};