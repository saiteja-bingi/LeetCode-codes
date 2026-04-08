// Last updated: 08/04/2026, 23:55:21
#define ll long long

/*
    arr[i]>arr[i-1] ans arr[i]>arr[i+1];
    increase arr[i]+1;
    maxiumize the special index;
    return min operations

    i will do these many operations so can i get available max index maximum
*/


class Solution {
public:
    long long minIncrease(vector<int>& arr) {
        ll n=arr.size();
        if(n%2!=0){
            ll sum=0;
            for(int i=1;i<n;i+=2){
                ll a=0;
                if(arr[i-1]>=arr[i]||arr[i+1]>=arr[i]){
                    a=max(arr[i+1],arr[i-1]);
                    sum+=a-arr[i]+1;
                }
            }
            return sum;
        }
        
        vector<ll>suf(n,0);
        suf[n-1]=0;
        ll a=0;
        if(n-2>=0&&n-3>=0&&(arr[n-1]>=arr[n-2]||arr[n-3]>=arr[n-2])){
            a=max(arr[n-1],arr[n-3]);
            suf[n-2]=a-arr[n-2]+1;
        }
        for(ll i=n-3;i>=0;i--){
            ll sum=0;
            suf[i]=suf[i+2];
            if(i-1>=0&&i+1<n&&(arr[i+1]>=arr[i]||arr[i-1]>=arr[i])){
                a=0;
                a=max(arr[i+1],arr[i-1]);
                suf[i]+=a-arr[i]+1;
            }
        }
        ll ans=LLONG_MAX,cur=0;
        for(ll i=1;i<n;){
            ans=min(ans,cur+suf[i]);
            if(i+1<n) ans=min(ans,cur+suf[i+1]);
            if(i-1>=0&&i+1<n){
                if(arr[i+1]>=arr[i]||arr[i-1]>=arr[i]){
                    a=0;
                    a=max(arr[i+1],arr[i-1]);
                    cur+=a-arr[i]+1;
                }
            }
            i+=2;
        }
        return ans;
        
    }
};