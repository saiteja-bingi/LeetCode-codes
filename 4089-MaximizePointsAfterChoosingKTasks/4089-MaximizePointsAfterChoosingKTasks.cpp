// Last updated: 1/11/2026, 11:10:09 AM
class Solution {
public:
    long long maxPoints(vector<int>& v1, vector<int>& v2, int k) {
        int n=v1.size();
        vector<pair<int,int>>diff(n);
        long long ans=0;
        for(int i=0;i<n;i++){
            diff[i]={v1[i]-v2[i],i};
        }
        sort(diff.begin(),diff.end());
        int c=0;
        for(int i=n-1;i>=0;i--){
            if(c<k) ans+=v1[diff[i].second];
            else{
                ans+=max(v1[diff[i].second],v2[diff[i].second]);
            }
            c++;
        }
        return ans;
    }
};