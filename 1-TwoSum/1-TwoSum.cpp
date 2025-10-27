// Last updated: 10/27/2025, 7:10:43 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        map<int,int>mp;
        int i,more,cur,j;
        for(i=0;i<arr.size();i++){
            cur=arr[i];
            more=target-cur;
            if(mp.find(more)!=mp.end()){
                return {i,mp[more]};
            }
            else{
                mp[cur]=i;
            }
        }
        return {};
    }
};