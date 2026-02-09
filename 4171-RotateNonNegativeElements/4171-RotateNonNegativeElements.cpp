// Last updated: 09/02/2026, 21:05:23
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n=nums.size();
        int pos=0,c=0;
        map<int,int>mp;
        map<int,int>mp2;
        map<int,int>mp1;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                c++;
                mp[i]=pos;
                mp1[pos]=i;
                mp2[i]=nums[i];
                pos++;
            } 
        }
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                int idx=(mp[i]+k)%c;
                int rp=mp1[idx];
                nums[i]=mp2[rp];
            }
        }
        return nums;
    }
};