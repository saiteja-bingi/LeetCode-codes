// Last updated: 15/04/2026, 00:45:25
class Solution {
public:
    int maxRepOpt1(string text) {
        unordered_map<char,int>mp;
        int n=text.size();
        for(int i=0;i<n;i++) mp[text[i]]++;
        int ans=0;
        for(auto [ch,fr]:mp){
            int l=0,c=0;
            for(int r=0;r<n;r++){
                if(text[r]==ch) c++;
                while(r-l+1>c+1){
                    if(text[l]==ch) c--;
                    l++;
                }
                ans=max(ans,min(r-l+1,fr));
            }
        }
        return ans;
    }
};