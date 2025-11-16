// Last updated: 11/16/2025, 4:57:35 PM
class Solution {
public:
    long long countDistinct(long long n) {
        string s=to_string(n);
        long long len=s.size();
        long long ans=0;
        for(int i=1;i<=len-1;i++){
            ans+=pow(9,i);
        }
        int i=0;
        while(i<len && s[i]!='0'){
            i++;
        }
        long long ans2 = 0;
        if(i==len){
            for(int k=0;k<len;k++){
                int d = s[k] - '0';
                ans2 += (long long)(d - 1) * pow(9, len - k - 1);
                if(d == 0) break;
                if(k == len - 1) ans2 += 1;
            }
            ans += ans2;
            return ans;
        }
        i--;
        while(i>=0 && s[i]=='1'){
            i--;
        }
        if(i<0){
            return ans;
        }
        ans2 = 0;
        for(int k=0;k<=i;k++){
            int d = s[k]-'0';
            if(k == i){
                ans2 += (long long)(d - 1) * pow(9, len - k - 1);
            } else {
                ans2 += (long long)(d-1) * pow(9, len - k - 1);
            }
        }

        ans += ans2;
        return ans;
    }
};
