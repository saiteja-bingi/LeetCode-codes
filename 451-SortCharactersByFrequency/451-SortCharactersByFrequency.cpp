// Last updated: 10/27/2025, 7:07:07 PM
class Solution {
public:
    static bool compare(pair<char,int>&a,pair<char,int>&b){
        if(a.second==b.second) return a.first<b.first;
        return a.second>b.second;
    }
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        s="";
        vector<pair<char,int>>vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),compare);
        for(auto &it:vec){
            s += string(it.second, it.first);
        }
        return s;
    }
};