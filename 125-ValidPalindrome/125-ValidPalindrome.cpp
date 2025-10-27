// Last updated: 10/27/2025, 7:09:17 PM
class Solution {
public:
    bool isPalindrome(string s) {
        // int n=s.length();
        string fil="";
        for(auto c:s){
            if(isalnum(c)){
                fil+=tolower(c);
            }
        }
        int n=fil.length();
        for(int i=0;i<n;i++){
            if(fil[i]!=fil[n-i-1]) return false;
        }
        return true;
    }
};