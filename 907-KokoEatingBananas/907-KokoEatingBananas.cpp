// Last updated: 10/27/2025, 7:06:41 PM
class Solution {
public:
    long long cal(vector<int>& piles,int mid){
        long long ans=0;
        for(int i=0;i<piles.size();i++){
            ans+=(piles[i]+mid-1)/mid;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ma=0;
        for(int i=0;i<piles.size();i++){
            ma=max(ma,piles[i]);
        }
        int low=1,high=ma,mid;
        int ans=ma;
        while(low<=high){
            mid=(low+high)/2;
            long long tt=cal(piles,mid);
            if(tt<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
}; 