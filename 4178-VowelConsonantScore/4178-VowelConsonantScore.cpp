// Last updated: 09/02/2026, 21:05:18
class Solution {
public:
    int vowelConsonantScore(string s) {
        set<char>st={'a','e','i','o','u'};
        int v=0,c=0;
        for(auto it:s){
            if(st.count(it)) v++;
            else if(it>=97&&it<=122) c++;
        }
        if(c>0) return v/c;
        else return 0;
    }
};