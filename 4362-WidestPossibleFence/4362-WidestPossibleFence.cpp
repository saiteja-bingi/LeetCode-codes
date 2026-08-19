// Last updated: 19/8/2026, 11:57:51 pm
class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        map<int,int>mp;
        for(auto it:planks) mp[it]++;
        map<int,int>mp2;
        vector<int>vec;
        for(auto&[x,y]:mp) vec.push_back(x);
        for(int i=0;i<vec.size();i++){
            mp2[vec[i]]+=mp[vec[i]];
            for(int j=0;j<=i;j++){
                if(i!=j) mp2[vec[i]+vec[j]]+=min(mp[vec[i]],mp[vec[j]]);
                else mp2[2*vec[i]]+=mp[vec[i]]/2;
            }
        }
        int ans=0;
        for(auto&[x,y]:mp2) ans=max(ans,y);
        return ans;
    }
};