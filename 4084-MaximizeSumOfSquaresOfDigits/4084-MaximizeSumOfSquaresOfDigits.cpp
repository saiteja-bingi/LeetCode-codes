// Last updated: 10/27/2025, 7:18:06 PM
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        string ans;
        while(num>0&&sum>0){
            if(sum>=9){
                ans+="9";
                sum-=9;
            }
            else{
                ans+=to_string(sum);
                sum=0;
            }
            num--;
        }
        while(num>0){
            ans+="0";
            num--;
        }
        return ans;
    }
};