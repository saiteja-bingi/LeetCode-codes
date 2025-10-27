// Last updated: 10/27/2025, 7:07:08 PM
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxlen=0,maxfreq=0;
        int hash[26]={0};
        int n=s.size();
        while(r<n){
            hash[s[r]-'A']++;
            maxfreq=max(maxfreq,hash[s[r]-'A']);
            if(((r-l+1)-maxfreq)>k){
                hash[s[l]-'A']--;
                maxfreq=0;
                l++;
            }
            if((r-l+1)-maxfreq<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};