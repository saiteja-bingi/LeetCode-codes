// Last updated: 10/27/2025, 7:09:41 PM
class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1) return x;
        long long low=1,high=x/2,mid,ans;
        while(low<=high){
            mid=(low+high)/2;
            if(mid*mid<=x){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};