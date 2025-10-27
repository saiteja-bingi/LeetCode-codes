// Last updated: 10/27/2025, 7:04:58 PM
class Solution {
public:
    bool isprime(int num){
        if(num<=1) return false;
        if(num==2||num==3) return true;
        if(num%2==0||num%3==0) return false;
        for(int i=5;i*i<=num;i+=6){
            if(num%i==0||num%(i+2)==0) return false;
        }
        return true;
    }
    long long splitArray(vector<int>& nums) {
        long long sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(isprime(i)){
                sum-=nums[i];
            }
            else{
                sum+=nums[i];
            }
        }
        return abs(sum);
    }
};