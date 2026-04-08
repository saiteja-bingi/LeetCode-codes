// Last updated: 08/04/2026, 23:54:34
class Solution {
public:
    /*
        i need to take the divisiors
        [100] max

        for each one i need to check whether it is sortable or not
        what should i do?

        1) i(max)<i+1(min) 
        2) we must only do cycle
        from min ele choose min(left,right) then traverse in one direction in cycle
        
    */
    vector<int> finddiv(int n){
        vector<int>ans;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                ans.push_back(i);
                if(i!=n/i) ans.push_back(n/i);
            }
        }
        return ans;
    }
    
    pair<bool,int> check(vector<int>&arr, int i, int j, int premax){
        int len = j - i + 1;
        int mi = INT_MAX, mx = INT_MIN;
        for(int k = i; k <= j; k++){
            mi = min(mi, arr[k]);
            mx = max(mx, arr[k]);
        }
        if(premax > mi) return {false, mx};
        
        // count drops in circular sense
        int drops = 0;
        for(int k = i; k <= j; k++){
            int next = i + (k - i + 1) % len;
            if(arr[k] > arr[next]) drops++;
            if(drops > 1) return {false, mx};
        }
        return {true, mx};
    }

    bool pos(vector<int>&arr,int ele){
        int n=arr.size();
        int k=0;
        int premax=INT_MIN;
        for(int i=ele*k;i<min(n,ele*(k+1));){
            cout<<ele<<endl;
            pair<bool,int>p=check(arr,i,min(n-1,ele*(k+1)-1),premax);
            if(!p.first) return false;
            premax=p.second;
            k++;
            i=ele*k;
        }
        return true;
    }
    
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int>div=finddiv(n);
        int sum=0;
        for(auto ele:div){
            if(pos(nums,ele)) sum+=ele;
        }
        return sum;
    }
};