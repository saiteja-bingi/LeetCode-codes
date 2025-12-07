// Last updated: 12/7/2025, 11:30:45 AM
1class Solution {
2public:
3    vector<int> sortByReflection(vector<int>& nums) {
4        int n=nums.size();
5        vector<pair<int,int>>vec(n);
6        for(int i=0;i<n;i++){
7            string s=bitset<32>(nums[i]).to_string();
8            s=s.substr(s.find('1'));
9            reverse(s.begin(), s.end());
10            int k=bitset<32>(s).to_ullong();
11            vec[i]={k,nums[i]};
12        }
13        sort(vec.begin(),vec.end());
14        vector<int>arr(n);
15        for(int i=0;i<n;i++){
16            arr[i]=vec[i].second;
17        }
18        return arr;
19    }
20};