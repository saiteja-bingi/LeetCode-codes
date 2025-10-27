// Last updated: 10/27/2025, 7:10:37 PM
class Solution {
public:
    int reverse(int x) {
        long long int rev=0;
        while(x!=0){
            int rem=x%10;
        if (rev > INT_MAX / 10|| (rev == INT_MAX / 10 && rem > 7)) return 0;
        if (rev < INT_MIN / 10|| (rev == INT_MAX / 10 && rem <-8)) return 0;
            rev=rev*10+rem;
            x/=10;
        }
        return rev;
    }
};