// Last updated: 10/27/2025, 7:06:09 PM
class Solution {
public:
    int beautySum(string s) {
        int sum=0,l,h;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int>mp;
            for(int j=i;j<s.size();j++){
                l=INT_MAX;
                h=INT_MIN;
                mp[s[j]]++;
                for(auto& it:mp){
                    h=max(h,it.second);
                    l=min(l,it.second);
                }
                sum+=(h-l);
            }
        }
        return sum;
    }
};