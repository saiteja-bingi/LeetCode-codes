// Last updated: 2/5/2026, 1:33:41 am
1#define ll long long
2class Solution {
3public:
4    int maxRotateFunction(vector<int>& arr) {
5        int n=arr.size();
6        // f(k)=f(k-1)+n*a[k-1]-sum;
7        long long sum=0,f0=0,f1=0;
8        for(int i=0;i<n;i++){
9            sum+=arr[i];
10            f0+=i*arr[i];
11        }
12        int ans=f0;
13        for(int i=1;i<n;i++){
14            f1=f0+n*arr[i-1]-sum;
15            ans=max(ans,(int)f1);
16            f0=f1;
17        }
18        return ans;
19    }
20};