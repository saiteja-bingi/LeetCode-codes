// Last updated: 10/27/2025, 7:06:27 PM
class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string se;
        for(auto it:s){
            if(count==0&&it=='('){
                count++;
            }
            else if(it=='('){
                count++;
                se+=it;
            }
            else if(count==1&&it==')'){
                count--;
            }
            else{
                count--;
                se+=it;
            }
        }
        return se;
    }
};