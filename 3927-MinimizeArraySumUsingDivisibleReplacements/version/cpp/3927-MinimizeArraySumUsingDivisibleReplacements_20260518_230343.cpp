// Last updated: 18/05/2026, 23:03:43
1class Solution {
2public:
3    long long minArraySum(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5        vector<int>temp(1e5+2,-1);
6        int n=nums.size();
7        if(nums[0]==1) return n;
8        for(int i=0;i<n;i++){
9            if(temp[nums[i]]==-1){
10                int j=1;
11                while(j <= 100000 / nums[i]){
12                    if(temp[j*nums[i]]==-1) temp[j * nums[i]] = nums[i];
13                    j++;
14                }
15            }
16        }
17        long long sum=0;
18        for(int i=0;i<n;i++){
19            sum+=temp[nums[i]];
20        }
21        return sum;
22    }
23};