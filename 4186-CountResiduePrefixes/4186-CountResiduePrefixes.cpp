// Last updated: 1/11/2026, 11:09:47 AM
class Solution {
public:
    int residuePrefixes(string s) {
        int n=s.size();
        map<char,int>mp;
        int c=1;
        int ans=1;
        mp[s[0]]++;
        for(int i=1;i<n;i++){
            mp[s[i]]++;
            if(mp[s[i]]==1){
                c++;
            }
            if(c==(i+1)%3) ans++;
        }
        return ans;
    }
};