// Last updated: 10/27/2025, 7:10:45 PM
class Solution {
public:
    bool ispal(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int low=0,high=0;
        int n=s.size();
        for(int center=0;center<s.size();center++){
            int i=center,j=center;
            while(i>=0&&j<n&&s[i]==s[j]){
                if(j-i > high-low){
                    low=i;
                    high=j;
                }
                i--;
                j++;
            }
            i=center;
            j=center+1;
            while(i>=0&&j<n&&s[i]==s[j]){
                if(j-i > high-low){
                    low=i;
                    high=j;
                }
                i--;
                j++;
            }
        }
        return s.substr(low,high-low+1);
    }
};