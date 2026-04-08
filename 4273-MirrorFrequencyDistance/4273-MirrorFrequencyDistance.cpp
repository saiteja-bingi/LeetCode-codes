// Last updated: 08/04/2026, 23:54:32
class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int>done;
        int n=s.size();
        map<char,int>mp;
        for(auto it:s) mp[it]++;
        int ans=0;
        for(auto it:s){
            if(done[it]) continue;
            char c=it,m;
            int k=c-'0';
            if(c>='0'&&c<='9') m=(9-k)+'0';
            else m=(char)('z'+'a'-c);
            // cout<<c<<" "<<m<<endl;
            ans+=abs(mp[m]-mp[c]);
            done[m]++;
            done[c]++;
        }
        return ans;
    }
};