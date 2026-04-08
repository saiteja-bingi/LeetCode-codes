// Last updated: 08/04/2026, 23:54:38
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int res=0;
        for(int i=0;i<n;i++){
            res^=nums1[i];res^=nums2[i];
        }
        if(res!=0) return -1;

        // possible with min cost
        unordered_map<int,int>mp1,mp2,tf;
        for(int i=0;i<n;i++){
            mp1[nums1[i]]++;
            mp2[nums2[i]]++;
            tf[nums1[i]]++;
            tf[nums2[i]]++;
        }
        unordered_map<int,int>targ;
        for(auto[x,y]:tf){
            targ[x]=y/2;
        }
        int ans=0;
        for(auto [x,y]:targ){
            ans+=abs(y-mp1[x]);
        }
        return ans/2;
    }
};