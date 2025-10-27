// Last updated: 10/27/2025, 7:06:48 PM
class Solution {
public:
    bool checkValidString(string s) {
        int min=0,max=0;
        for(char it:s){
            if(it=='('){
                min++; 
                max++;
            }
            else if(it==')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }
            if(min<0) min++;
            if(max<0) return false;
        }
        return !min;
    }
};