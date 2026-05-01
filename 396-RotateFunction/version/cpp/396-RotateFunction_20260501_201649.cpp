// Last updated: 1/5/2026, 8:16:49 pm
1#define ll long long
2class Solution {
3public:
4    int maxRotateFunction(vector<int>& arr) {
5        ll z = 0;
6        ll s = arr[0];
7        for(int i = 1;i<arr.size();i++){
8            z+=arr[i]*i;
9            s+=arr[i];
10        }
11        ll pre = z;
12        for(int i = 1;i<arr.size();i++){
13            ll cur = pre + s - arr.size()*arr[arr.size()-i];
14            z = max(z,cur);
15            pre = cur;
16        }
17        return z;
18    }
19};