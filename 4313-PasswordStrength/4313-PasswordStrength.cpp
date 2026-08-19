// Last updated: 19/8/2026, 11:58:31 pm
class Solution {
public:
    int passwordStrength(string p) {
        unordered_map<char,int>mp;
        int ans=0;
        for(int i=0;i<p.size();i++){
            char ch=p[i];
            if(!mp[ch]){
                if('a'<=ch&&ch<='z') ans+=1;
                else if('A'<=ch&&ch<='Z') ans+=2;
                else if('0'<=ch&&ch<='9') ans+=3;
                else ans+=5;
            }
            mp[ch]++;
        }
        return ans;
    }
};