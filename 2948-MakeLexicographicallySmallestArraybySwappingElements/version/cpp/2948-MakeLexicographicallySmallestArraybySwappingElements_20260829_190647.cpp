// Last updated: 29/8/2026, 7:06:47 pm
1class Solution {
2public:
3    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
4        int n=nums.size();
5        vector<int>ans(n);
6        vector<pair<int,int>>arr(n);
7        for(int i=0;i<n;i++) arr[i]={nums[i],i};
8        sort(arr.begin(),arr.end());
9        set<int>st;
10        st.insert(arr[0].second);
11        vector<int>temp;temp.push_back(arr[0].first);
12        for(int i=1;i<n;i++){
13            if(arr[i].first-arr[i-1].first>limit){
14                int j=0;
15                for(auto it:st) {ans[it]=temp[j];j++;}
16                st.clear();
17                temp.clear();
18            }
19            st.insert(arr[i].second);
20            temp.push_back(arr[i].first);
21        }
22        int j=0;
23        for(auto it:st) {ans[it]=temp[j];j++;}
24        return ans;
25    }
26};
27
28