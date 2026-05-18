// Last updated: 18/5/2026, 11:13:32 pm
1class Solution {
2public:
3    vector<int> scoreValidator(vector<string>& events) {
4        int sc=0,c=0;
5        for(auto it:events){
6            if(it=="W") c++;
7            else if(it=="WD"||it=="NB") sc+=1;
8            else sc+=stoi(it);
9            if(c==10) break;
10        }
11        return {sc,c};
12    }
13};