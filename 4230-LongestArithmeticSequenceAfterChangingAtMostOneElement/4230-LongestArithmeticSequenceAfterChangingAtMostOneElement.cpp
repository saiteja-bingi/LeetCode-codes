// Last updated: 08/04/2026, 23:54:51
class Solution {
public:
    int longestArithmetic(vector<int>& arr) {
        int n=arr.size();
        if(n<=2) return n;
        vector<int>left(n,2),right(n,2);
        for(int i=2;i<n;i++){
            if(arr[i]-arr[i-1]==arr[i-1]-arr[i-2]) left[i]=left[i-1]+1;
        }
        for(int i=n-3;i>=0;i--){
            if(arr[i+1]-arr[i]==arr[i+2]-arr[i+1]) right[i]=right[i+1]+1;
        }
        int ans=2;
        for(int i=0;i<n;i++){
            ans=max(ans,max(left[i],right[i]));
            if(i==0){
                ans=max(ans,right[i+1]+1);
            }
            else if(i==n-1){
                ans=max(ans,left[i-1]+1);
            }
            else{
                ans=max(ans,right[i+1]+1);
                ans=max(ans,left[i-1]+1);
                if((arr[i+1]-arr[i-1])%2==0){
                    int req=(arr[i+1]-arr[i-1])/2;
                    int l=1,r=1;
                    if(i-2>=0&&arr[i-1]-arr[i-2]==req){
                        l=left[i-1];
                    }
                    if(i+2<n&&arr[i+2]-arr[i+1]==req){
                        r=right[i+1];
                    }
                    ans=max(ans,l+r+1);
                }
            }
        }
        return ans;
    }
};