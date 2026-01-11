// Last updated: 1/11/2026, 11:10:06 AM
class Solution {
public:

    bool prime(int num){
        if(num<=1) return false;
        for(int i=2;i*i<=num;i++){
            if(num%i==0) return false;
        }
        return true;
    }
    bool completePrime(int num) {
        int k=num;
        if(!prime(k)) return false;
        string s=to_string(num);
        int n=s.size();
        for(int i=0;i<n;i++){
            long long p=stoll(s.substr(0,i+1));
            long long su=stoll(s.substr(i,n));
            if(!prime(p)||!prime(su)) return false;
        }
        return true;
    }
};