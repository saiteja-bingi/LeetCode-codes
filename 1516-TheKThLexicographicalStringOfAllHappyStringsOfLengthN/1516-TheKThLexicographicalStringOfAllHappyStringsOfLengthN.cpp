// Last updated: 15/04/2026, 00:45:18
class Solution {
public:
    string getHappyString(int n, int k) {
        if(k>3*(1<<(n-1))){
            return "";
        }
        string ans="";
        string prev="d";
        for(int i=0;i<n;i++){
            int rem=n-i-1;
            for(auto ch:{"a","b","c"}){
                if(ch==prev) continue;
                int block=(1<<rem);
                if(k>block){
                    k-=block;
                }
                else{
                    ans+=ch;
                    prev=ch;
                    break;
                }
            }
        }
        return ans;
    }
};