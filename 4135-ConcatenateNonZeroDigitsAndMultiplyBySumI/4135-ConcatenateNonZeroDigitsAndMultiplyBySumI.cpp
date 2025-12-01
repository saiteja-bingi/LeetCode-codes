// Last updated: 12/1/2025, 7:13:02 PM
class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        long long sum=0;
        string s2="";
        for(auto it:s){
            if(it!='0'){
                s2+=it;
                sum+=(it-'0');
            }
        }
        long long num=0;
        if(!s2.empty()) num=stoll(s2);
        return num*sum;
    }
};