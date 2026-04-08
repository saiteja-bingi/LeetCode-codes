// Last updated: 08/04/2026, 23:55:04
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int>mp;
        for(auto it:bulbs){
            mp[it]++;
        }
        vector<int>arr;
        for(auto[x,y]:mp){
            if(y%2!=0) arr.push_back(x);
        }
        return arr;
    }
};