// Last updated: 8/7/2026, 2:52:12 pm
1class Solution {
2public:
3    int maxDigitRange(vector<int>& nums) {
4        int n=nums.size();
5        int me=INT_MIN;
6        for(int i=0;i<n;i++){
7            int num=nums[i];
8            int a=INT_MAX,b=INT_MIN;
9            while(num>0){
10                int r=num%10;
11                a=min(a,r);
12                b=max(b,r);
13                num/=10;
14            }
15            me=max(me,b-a);
16        }
17        int ans=0;
18        for(int i=0;i<n;i++){
19            int num=nums[i];
20            int a=INT_MAX,b=INT_MIN;
21            while(num>0){
22                int r=num%10;
23                a=min(a,r);
24                b=max(b,r);
25                num/=10;
26            }
27            if(b-a==me) ans+=nums[i];
28        }
29        return ans;
30    }
31};