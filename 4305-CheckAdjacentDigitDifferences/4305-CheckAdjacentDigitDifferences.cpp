// Last updated: 19/8/2026, 11:58:40 pm
class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int sum=0;
        for(int i=0;i<s.size()-1;i++){
            sum=abs((s[i]-'0')-(s[i+1]-'0'));
            if(sum>2) return false;
        }
        return true;
    }
};