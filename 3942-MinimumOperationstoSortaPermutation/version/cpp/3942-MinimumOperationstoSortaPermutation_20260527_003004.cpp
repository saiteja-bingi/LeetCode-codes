// Last updated: 27/05/2026, 00:30:04
1class Solution {
2public:
3    int minOperations(vector<int>& nums) {
4        int n=nums.size();
5        bool y=false;
6        int c1=0,c2=0;
7        int i=0;
8        for(i=0;i<2*n-1;i++){
9            int j=i%n;
10            if(nums[j]<nums[(j+1)%n]){
11                c1++;
12                c2=1;
13            }
14            else{
15                c2++;
16                c1=1;
17            }
18            if(c1==n||c2==n){
19                y=true;
20                break;
21            }
22        }
23        if(y==0) return -1;
24
25        int c=1;
26        for(int i=0;i<n-1;i++) if(nums[i]<nums[i+1]) c++;
27        if(c==n) return 0;
28
29        i++;
30        cout<<i<<endl;
31        int x=0;
32        if(i<n) x=n-i;
33        else{
34            int j=2*n-1-i+((c1==n)?2:0);
35            int k=i-n+1;
36            cout<<j<<" "<<k<<endl;
37            x=min(j,k);
38        }
39        cout<<x<<endl;
40        return x+((c1==n)?0:1);
41        // return (c1==n)?1:0;
42    }
43    /*
44        what is the min op?
45
46    */
47};