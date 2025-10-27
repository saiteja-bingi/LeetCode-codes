// Last updated: 10/27/2025, 7:07:40 PM
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>vis(nums2.size(),0);
        unordered_set<int>ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]&&vis[j]==0){
                    ans.insert(nums1[i]);
                    vis[j]=1;
                    break;
                }
            }
        }
        vector<int>a;
        for(auto it :ans){
            a.push_back(it);
        }
        return a;
    }
};