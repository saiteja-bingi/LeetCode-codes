// Last updated: 12/1/2025, 7:13:05 PM

class Solution {
public:
    int minimumDistance(vector<int>& arr) {
        int n=arr.size();
        int ans=INT_MAX;
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        for(auto &[x,vec]:mp){
            if(vec.size()>=3){
                int i=0,j=1,k=2;
                int m=vec.size();
                int c=INT_MAX;
                while(k<m){
            c=min(abs(vec[i]-vec[j])+abs(vec[j]-vec[k])+abs(vec[k]-vec[i]),c);
                    i++;
                    j++;
                    k++;
                }
                ans=min(ans,c);
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};