// Last updated: 19/8/2026, 11:58:08 pm
class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int c=i;
            for(int j=0;j<n/2;j++){
                int a=(j+i)%n,b=(n-j-1+i)%n;
                char x=s[a],z=s[b];
                c+=min((z-x+26)%26,(x-z+26)%26);
            }
            ans=min(ans,c);
        }
        return ans;
    }
};