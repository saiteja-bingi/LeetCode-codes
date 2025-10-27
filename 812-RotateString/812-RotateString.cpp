// Last updated: 10/27/2025, 7:20:26 PM
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        s=s+s;
        int count=0,j=0;
        for(int i=0;i<s.size()&&j<goal.size();i++){
            if(s[i]==goal[j]){
                count++;
                j++;
                if (j == goal.size()) return true;
            }
            else{
                i-=j;
                count=0;
                j=0;
            }
        }
        if(count==goal.size()) return true;
        else return false;
    }
};