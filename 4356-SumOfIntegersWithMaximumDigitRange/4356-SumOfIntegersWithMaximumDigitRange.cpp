// Last updated: 19/8/2026, 11:57:56 pm
class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n=nums.size();
        int me=INT_MIN;
        for(int i=0;i<n;i++){
            int num=nums[i];
            int a=INT_MAX,b=INT_MIN;
            while(num>0){
                int r=num%10;
                a=min(a,r);
                b=max(b,r);
                num/=10;
            }
            me=max(me,b-a);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int num=nums[i];
            int a=INT_MAX,b=INT_MIN;
            while(num>0){
                int r=num%10;
                a=min(a,r);
                b=max(b,r);
                num/=10;
            }
            if(b-a==me) ans+=nums[i];
        }
        return ans;
    }
};