// Last updated: 10/27/2025, 7:06:22 PM
class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        int n=s.size();
        int l=0;
        int r=0;
        int hash[3]={0};
        while(r<n){
            hash[s[r]-'a']++;
            while(hash[0]>0&&hash[1]>0&&hash[2]>0){
                if(hash[0]>0&&hash[1]>0&&hash[2]>0){
                    count+=n-r;
                }
                hash[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return count;
    }
};