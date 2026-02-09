// Last updated: 09/02/2026, 21:05:09
class Solution {
public:
    string reverseByType(string s) {
        vector<char> a,b;
        for(auto it:s){
            if(it>=97&&it<=122){
                a.push_back(it);
            }
            else b.push_back(it);
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0,j=0;
        string ans="";
        for(auto it:s){
            if(it>=97&&it<=122){
                ans+=a[i];
                i++;
            }
            else {ans+=b[j];j++;}
        }
        return ans;
    }
};