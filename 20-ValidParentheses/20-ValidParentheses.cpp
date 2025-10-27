// Last updated: 10/27/2025, 7:10:27 PM
class Solution {
public:
    bool isValid(string str) {
        stack<char>st;
        for(auto s:str){
            if(s=='('||s=='{'||s=='['){
                st.push(s);
            }else{
                if (st.empty()) return false;
                if (s == ')' && st.top() == '(') st.pop();
                else if (s == '}' && st.top() == '{') st.pop();
                else if (s == ']' && st.top() == '[') st.pop();
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};