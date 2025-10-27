// Last updated: 10/27/2025, 7:05:04 PM
class Solution {
public:
    bool hasSameDigits(string s) {
        int n=s.size();
        while(n>2){
        for(int i=0,j=1;j<n;i++,j++){
            s[i]=((int)(s[i]-'0')+(int)(s[j]-'0'))%10-'0';
        }
        n--;
        }
        if(s[0]==s[1]){
            return true;
        }
        return false;
    }
};