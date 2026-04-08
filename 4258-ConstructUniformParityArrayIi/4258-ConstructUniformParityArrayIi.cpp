// Last updated: 08/04/2026, 23:54:33
class Solution {
public:
    bool uniformArray(vector<int>& arr) {
        int n=arr.size();
        int o=INT_MIN,e=INT_MIN,om=INT_MAX;
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2!=0){
                o=max(o,arr[i]);c1++;
                om=min(om,arr[i]);
            }
            else{
                e=max(arr[i],e);c2++;
            }
        }
        cout<<c1<<" "<<c2<<endl;
        if(c1==n||c2==n) return true;
        for(int i=0;i<n;i++){
            if(arr[i]%2==0){
                if(arr[i]<om) return false;
            }
        }
        return true;
    }
};