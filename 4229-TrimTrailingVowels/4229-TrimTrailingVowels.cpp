// Last updated: 08/04/2026, 23:54:52
class Solution {
public:
    string trimTrailingVowels(string s) {
        set<char>st={'a','e','i','o','u'};
        string ans="";
        int i=0,j=s.size()-1;
        // while(st.count(s[i])) i++;
        while(j>=0&&st.count(s[j])) j--;
        i=0;
        while(i<=j){
            ans+=s[i];
            i++;
        }
        return ans;
    }
};