// Last updated: 1/11/2026, 11:09:52 AM
class Solution {
public:
    string largestEven(string s) {
        int n=s.size();
        int i=n-1;
        while(i>=0){
            if(s[i]=='1') i--;
            else break;
        }
        string ans="";
        for(int j=0;j<=i;j++){
            ans+=s[j];
        }
        return ans;
    }
};