// Last updated: 12/1/2025, 7:13:10 PM
class Solution {
public:
    int minimumDistance(vector<int>& arr) {
        int n=arr.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i]==arr[j]&&arr[j]==arr[k]&&arr[k]==arr[i]){
                        int c=abs(i-j)+abs(j-k)+abs(k-i);
                        ans=min(ans,c);
                    }
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};