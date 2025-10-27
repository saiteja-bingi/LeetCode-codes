// Last updated: 10/27/2025, 7:06:26 PM
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int mn=0,maxw=0;
        // to find max element and sum of array
        for(int i=0;i<weights.size();i++){
            maxw+=weights[i];
            mn=max(mn,weights[i]);
        }
        int low=mn,high=maxw,mid,ans;
        while(low<=high){
            mid=(low+high)/2;
            int countday=1,sum=0;
            for(int j=0;j<weights.size();j++){
                if(sum+weights[j]>mid){
                    sum=0;
                    countday++;
                }
                sum+=weights[j];
            }
            if(countday<=days){
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