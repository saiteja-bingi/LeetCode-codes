// Last updated: 13/7/2026, 10:51:36 am
1class Solution {
2public:
3    vector<int> sequentialDigits(int low, int high) {
4        vector<int>ans;
5        int l=0,r=0;
6        int k=low;
7        while(k>0){
8            l++;
9            k/=10;
10        }
11        k=high;
12        while(k>0){
13            r++;
14            k/=10;
15        }
16        for(int sz=l;sz<=r;sz++){
17            string s="";
18            int c=1,num=sz;
19            while(num){
20                s+=to_string(c);
21                c++;
22                num--;
23            }
24            while(c<=10){
25                int x=stoi(s);
26                if(x>=low&&x<=high) ans.push_back(x);
27                s.erase(0,1);
28                s+=to_string(c);
29                c++;
30            }
31        }
32        return ans;
33    }
34};