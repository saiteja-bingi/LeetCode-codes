// Last updated: 19/5/2026, 10:47:00 am
1class Solution {
2public:
3    int compareBitonicSums(vector<int>& nums) {
4        int x=INT_MIN,y=INT_MAX;
5        int t=max_element(nums.begin(),nums.end())-nums.begin();
6        y=nums[t];
7        long long c1=0,c2=0;
8        for(int i=0;i<nums.size();i++){
9            int it=nums[i];
10            if(x<it){
11                c1+=it;
12                x=it;
13            }
14            if(i>=t&&y>=it){
15                c2+=it;
16                y=it;
17            }
18        }
19        // cout<<c1<<" "<<c2<<endl;
20        return (c1==c2)?-1:(c2>c1);
21    }
22};