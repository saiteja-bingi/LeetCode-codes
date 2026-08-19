// Last updated: 19/8/2026, 11:57:58 pm
class Solution {
public:
    int largestInteger(int n, int s) {
        if(9*n<s) return -1;
        int ans=0,sum=0;
        while(n--){
            ans=ans*10+min(9,s-sum);
            sum+=min(9,s-sum);
        }
        return ans;
    }
};