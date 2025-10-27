// Last updated: 10/27/2025, 7:06:19 PM
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k) return -1;
        int mi=INT_MAX,ma=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<mi) mi=min(mi,bloomDay[i]);
            if(bloomDay[i]>ma) ma=max(ma,bloomDay[i]);
        }
        int ans=ma;
        int low=mi,high=ma,mid;
        while(low<=high){
            mid=(low+high)/2;
            int buck=0;
            int count=0;
            for(int j=0;j<bloomDay.size();j++){
                if(bloomDay[j]<=mid) count++;
                else{
                    buck+=count/k;
                    count=0;
                }
            }
            buck+=count/k;
            if(buck>=m){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};