// Last updated: 10/27/2025, 7:10:33 PM
class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        unordered_map<char,int>mp{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int n=s.size();
        ans+=mp[s[n-1]];
        for(int i=n-2;i>=0;i--){
            if(mp[s[i]]<mp[s[i+1]]) ans-=mp[s[i]];
            else ans+=mp[s[i]];
        }
        return ans;
    }
};