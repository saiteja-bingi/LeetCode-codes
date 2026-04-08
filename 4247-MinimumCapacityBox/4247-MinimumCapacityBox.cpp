// Last updated: 08/04/2026, 23:54:44
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int idx=-1,r=INT_MAX;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize){
                if(capacity[i]<r){
                    r=capacity[i];
                    idx=i;
                }
            }
        }
        return idx;
    }
};