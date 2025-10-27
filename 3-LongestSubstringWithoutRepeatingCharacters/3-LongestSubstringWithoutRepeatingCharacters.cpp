// Last updated: 10/27/2025, 7:10:38 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int maxlen=0;
        int l=0;
        int r=0;
        int n=s.size();
        while(r<n){
            while(mp[s[r]]!=0){
                mp[s[l]]--;
                l++;
            }
            mp[s[r]]++;
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};