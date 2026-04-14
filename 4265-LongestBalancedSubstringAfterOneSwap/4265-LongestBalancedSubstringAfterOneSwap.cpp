// Last updated: 15/04/2026, 00:42:32
class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        unordered_map<int,vector<int>>mp;
        mp[0].push_back(-1);
        int c1=0,c0=0;
        for(auto it:s){
            if(it=='1') c1++;
            else c0++;
        }
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') sum--;
            else sum++;
            if(mp.count(sum)){
                ans=max(ans,i-mp[sum][0]);
            }
            // more 0s
            if(mp.count(sum+2)){
                auto arr=mp[sum+2];
                for(int j=0;j<arr.size();j++){
                    int len=i-arr[j];
                    int o=(len-2)/2;
                    if(c1>o){
                        ans=max(ans,len);
                        break;
                    }
                }
            }
            // more 1s
            if(mp.count(sum-2)){
                auto arr=mp[sum-2];
                for(int j=0;j<arr.size();j++){
                    int len=i-arr[j];
                    int z=(len-2)/2;
                    if(c0>z){
                        ans=max(ans,len);
                        break;
                    }
                }
            }
            if(mp[sum].size()<=1) mp[sum].push_back(i);
        }
        return ans;
    }
};