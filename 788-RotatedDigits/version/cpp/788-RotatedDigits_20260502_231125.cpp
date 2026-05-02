// Last updated: 2/5/2026, 11:11:25 pm
1class Solution {
2public:
3    int rotatedDigits(int n) {
4        // only contain 2 5 6 9
5        unordered_map<int,int>mp;
6        mp[2]=5;mp[6]=9;
7        mp[5]=2;mp[9]=6;
8        mp[0]=0;mp[1]=1;mp[8]=8;
9        int c=0;
10        for(int i=1;i<=n;i++){
11            int num=i;
12            bool f=0;
13            int k=0;
14            int l=1;
15            while(num>0){
16                int r=num%10;
17                if(!mp.count(r)){
18                    f=1;
19                    break;
20                }
21                k=mp[r]*l+k;
22                num/=10;
23                l*=10;
24            }
25            if(!f&&k!=i){
26                c++;
27            }
28        }
29        return c;
30    }
31};