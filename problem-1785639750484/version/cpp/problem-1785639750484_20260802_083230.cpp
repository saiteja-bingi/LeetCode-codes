// Last updated: 2/8/2026, 8:32:30 am
1class Solution {
2public:
3    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
4        int n=tasks.size(),m=shifts.size();
5        vector<int>ans(m);
6        vector<long long>arr(n);
7        arr[0]=tasks[0];
8        for(int i=1;i<n;i++) arr[i]+=tasks[i]+arr[i-1];
9        long long lst=0;
10        long long t=arr[n-1],c=0;
11        for(int i=0;i<m;i++){
12            int k=shifts[i];
13            c+=k;
14            if(c>=t){
15                c=0;
16                ans[i]=0;
17                continue;
18            }
19            auto it=upper_bound(arr.begin(),arr.end(),c)-arr.begin();
20            ans[i]=n-it;
21        }
22        return ans;
23    }
24};