// Last updated: 10/27/2025, 7:06:34 PM
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int n=fruits.size();
        int l=0,r=0;
        int maxlen=0;
        int k=2;
        while(r<n){
            if(mp[fruits[r]]==0){
                k--;
            }
            mp[fruits[r]]++;
            if(k<0){
                if(mp[fruits[l]]==1) k++;
                mp[fruits[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};