// Last updated: 10/27/2025, 7:06:40 PM
class Solution {
    vector<int> findnextSmall(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> findprevSmall(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nextSmall=findnextSmall(arr);
        vector<int>prevSmall=findprevSmall(arr);
        long long total=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            int left=i-prevSmall[i];
            int right=nextSmall[i]-i;
            total=(total+(1LL*right*left*arr[i])%mod)%mod;
        }
        return (int)total;
    }
};