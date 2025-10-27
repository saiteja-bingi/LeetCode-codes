// Last updated: 10/27/2025, 7:10:34 PM
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int o=x;
        int long long rev=0;
        while(x>0){
            int rem=x%10;
            rev=rev*10+rem;
            x/=10;
        }
        return (rev==o);
    }
};