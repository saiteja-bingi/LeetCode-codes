// Last updated: 10/27/2025, 7:05:53 PM
class Solution {
public:
    int countDigits(int num) {
        int original=num, count=0;
        while(num>0){
            int digit=num%10;
            if(original%digit==0) count++;
            num/=10;
        }
        return count;
    }
};
