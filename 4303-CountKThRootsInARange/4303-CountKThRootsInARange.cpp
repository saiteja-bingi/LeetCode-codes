// Last updated: 19/8/2026, 11:58:41 pm
#define ll long long
ll mod=1e9+7;
class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k==1){
            return r-l+1;
        }
        int m=ceil(pow(l,1.0/k));
        int n=floor(pow(r,1.0/k));
        int e1=m-1,e2=n+1;
        ll v=1,c=0;
        for(int i=0;i<k;i++){
            if((__int128)v*e1>1e9){
                v=1e9+1;
                break;
            }
            v*=e1;
        }
        if(e1>=0&&v<=r&&v>=l) c++;
        v=1;
        for(int i=0;i<k;i++){
            if((__int128)v*e2>1e9){
                v=1e9+1;
                break;
            }
            v*=e2;
        }
        if(e2<=1e9&&v<=r&&v>=l) c++;
        return max(0,n-m+1)+c;
    }
};