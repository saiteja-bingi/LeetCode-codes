// Last updated: 10/27/2025, 7:07:51 PM
class Solution {
public:
    int addDigits(int num) {
        while(num%10!=num){
            int sum=0;
            int n=num;
            while(n>0){
                sum+=n%10;
                n/=10;
            }
            num=sum;
        }
        return num;
    }
};