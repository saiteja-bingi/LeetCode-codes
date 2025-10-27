// Last updated: 10/27/2025, 7:07:52 PM
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xrn=0;
        for(auto it:nums){
            xrn^=it;
        }
        long rightmost=(xrn&(xrn-1))^xrn;

        int b1=0,b2=0;
        for(auto it:nums){
            if(it&rightmost){
                b1^=it;
            }
            else{
                b2^=it;
            }
        }
        return {b1,b2};
    }
};