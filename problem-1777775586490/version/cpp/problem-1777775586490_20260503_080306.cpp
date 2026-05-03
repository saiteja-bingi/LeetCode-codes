// Last updated: 3/5/2026, 8:03:06 am
1class Solution {
2public:
3    vector<int> countOppositeParity(vector<int>& arr) {
4        int n=arr.size();
5        vector<int>ans(n,0);
6        for(int  i=0;i<n;i++){
7            int c=0;
8            for(int j=i+1;j<n;j++){
9                if(i!=j&&(arr[i]+arr[j])&1) c++;
10            }
11            ans[i]=c;
12        }
13        return ans;
14    }
15};