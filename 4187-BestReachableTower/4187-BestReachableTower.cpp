// Last updated: 09/02/2026, 21:05:15
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        sort(towers.begin(),towers.end(),[](vector<int>& a, vector<int>& b){
            if(a[2]!=b[2]) return a[2]>b[2];
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]<b[1];
        });
        bool a=false;
        vector<int>b;
        for(int i=0;i<towers.size();i++){
            int k=abs(center[0]-towers[i][0])+abs(center[1]-towers[i][1]);
            if(k<=radius){
                a=true;
                b.push_back(towers[i][0]);
                b.push_back(towers[i][1]);
                break;
            }
        }
        if(a) return b;
        return {-1,-1};
    }
};