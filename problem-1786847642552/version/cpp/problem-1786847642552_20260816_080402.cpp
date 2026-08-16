// Last updated: 16/08/2026, 08:04:02
1class Solution {
2public:
3    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
4        int idx=-1,val=INT_MAX;
5        for(int i=0;i<drones.size();i++){
6            int k=abs(target[0]-drones[i][0])+abs(target[1]-drones[i][1]);
7            if(drones[i][2]>=k){
8                if(k<val){
9                    val=k;
10                    idx=i;
11                }
12            }
13        }
14        return idx;
15    }
16};