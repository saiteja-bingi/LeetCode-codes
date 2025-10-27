// Last updated: 10/27/2025, 7:09:01 PM
class Solution {
public:
    string reverseWords(string s) {
        stack<string>stk;
        string se="";
        for(int i=0;i<=s.size()-1;i++){
            if(s[i]!=' '){
                se+=s[i];
            }
            else if(!se.empty()){
                stk.push(se);
                se="";
            }
        }
        if(!se.empty()){
            stk.push(se);
        }
        se="";
        while(!stk.empty()){
            se+=stk.top();
            se+=" ";
            stk.pop();
        }
        se.pop_back();
        return se;
    }
};