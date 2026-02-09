// Last updated: 09/02/2026, 21:05:43
class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& cap, int budget) {
        int n=costs.size();
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++) arr[i]={costs[i],cap[i]};
        sort(arr.begin(),arr.end());
        // for 1 machine
        int ans1=0,ans2=0;
        for(int i=0;i<n;i++){
            if(arr[i].first<budget) ans1=max(ans1,arr[i].second);
        }
        vector<int>premax(n);
        premax[0]=arr[0].second;
        for(int i=1;i<n;i++){
            premax[i]=max(premax[i-1],arr[i].second);
        }
        // for 2 machines
        for(int i=1;i<n;i++){
            int l=0,r=i-1,mid;
            while(l<=r){
                mid=(l+r)/2;
                if(arr[mid].first<budget-arr[i].first){
                    ans2=max(ans2,arr[i].second+premax[mid]);
                    l=mid+1;
                }
                else r=mid-1;
            }
        }
        return max(ans1,ans2);
    }
};