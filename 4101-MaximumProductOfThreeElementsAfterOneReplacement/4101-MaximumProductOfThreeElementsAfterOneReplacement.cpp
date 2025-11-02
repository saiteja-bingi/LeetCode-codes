// Last updated: 11/2/2025, 12:12:45 PM
class Solution {
public:
    long long maxProduct(vector<int>& arr) {
        int n=arr.size();
        long long ans=pow(10,5);
        int c=0,i=0,j=n-1;
        sort(arr.begin(),arr.end());
        while(i<=j&&c<2){
            int k1=arr[i],k2=arr[j];
            if(k1<0) k1*=-1;
            if(k2<0) k2*=-1;
            if(k1>k2){
                ans*=arr[i];
                i++;
            }
            else{
                ans*=arr[j];
                j--;
            }
            c++;
        }
        if(ans<0) return -1*ans;
        return ans;
    }
};