// Last updated: 3/5/2026, 7:46:20 am
1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4        if(s.size()!=goal.size()) return false;
5        s=s+s;
6        int count=0,j=0;
7        for(int i=0;i<s.size()&&j<goal.size();i++){
8            if(s[i]==goal[j]){
9                count++;
10                j++;
11                if (j == goal.size()) return true;
12            }
13            else{
14                i-=j;
15                count=0;
16                j=0;
17            }
18        }
19        if(count==goal.size()) return true;
20        else return false;
21    }
22};