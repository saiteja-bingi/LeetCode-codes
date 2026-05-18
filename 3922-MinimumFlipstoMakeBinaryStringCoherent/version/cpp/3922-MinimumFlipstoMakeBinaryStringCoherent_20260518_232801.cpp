// Last updated: 18/5/2026, 11:28:01 pm
1class Solution {
2public:
3    int minFlips(string s) {
4        int c1=0,c2=0;
5        int n=s.size();
6        int a=0,b=0;
7        for(int i=0;i<n;i++){
8            if(s[i]=='1') a++;
9            else b++;
10        }
11        int i=0,j=n-1;
12        while(i<n&&s[i]=='0') i++;
13        i++;
14        while(j>=0&&s[j]=='1') j--;
15        j--;
16        while(i<=j){
17            if(s[i]=='1'){
18                s[i]='0';
19                c1++;
20            }
21            i++;
22        }
23        
24        i=0;j=n-1;
25        while(i<n&&s[i]=='1') i++;
26        i++;
27        while(j>=0&&s[j]=='0') j--;
28        j--;
29        while(i<=j){
30            if(s[i]=='1') c2++;
31            i++;
32        }
33        return min({c1+c2,a,b});
34    }
35};