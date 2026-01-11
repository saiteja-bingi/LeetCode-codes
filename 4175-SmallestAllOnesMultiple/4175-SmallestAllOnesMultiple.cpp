// Last updated: 1/11/2026, 11:09:51 AM
class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2==0||k%5==0) return -1;
        int len=1;
        long long num=1;
        while(num<=LLONG_MAX/10&&num%k!=0){
            num=(num*10+1)%k;
            len++;
        }
        return len;
    }
};