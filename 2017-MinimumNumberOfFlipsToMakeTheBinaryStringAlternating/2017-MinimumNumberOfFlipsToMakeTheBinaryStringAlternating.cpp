// Last updated: 15/04/2026, 00:44:55
class Solution {
public:

    /*
        ok observation....
        remove start ele and add to last --->rotation so s=s+s maxkes it well
        110001 --> 110001 + 110001
        now i choose the window of size n where it has maximum no of alternating characters
    sliding window ig

    */
    int minFlips(string s) {
        int n=s.size();
        s=s+s;
        string s1="",s2="";

        for(int i=0;i<2*n;i++){
            if(i%2==0){
                s1+="0";
                s2+="1";
            }
            else{
                s1+="1";
                s2+="0";
            }
        }
        int i=0,k1=0,k2=0;
        int ans=INT_MAX;
        for(int j=0;j<2*n;j++){
            if(s[j]!=s1[j]) k1++;
            if(s[j]!=s2[j]) k2++;

            if(j-i+1>n){
                if(s1[i]!=s[i]) k1--;
                if(s2[i]!=s[i]) k2--;
                i++;
            }
            if(j-i+1==n){
                ans=min({ans,k1,k2});
            }
        }
        return ans;
    }
};