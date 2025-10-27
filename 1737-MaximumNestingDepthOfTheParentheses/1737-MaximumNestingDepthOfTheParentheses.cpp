// Last updated: 10/27/2025, 7:06:17 PM
class Solution {
public:
    int maxDepth(string s) {
        int count=0,ans=0;
        for(auto it:s){
            if(it=='('){
                count++;
                ans=max(count,ans);
            }
            else if(it==')'){
                count--;
            }
        }
        return ans;
    }
};