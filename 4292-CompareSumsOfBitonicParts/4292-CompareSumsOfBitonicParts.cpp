// Last updated: 19/8/2026, 11:58:58 pm
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int x=INT_MIN,y=INT_MAX;
        int t=max_element(nums.begin(),nums.end())-nums.begin();
        y=nums[t];
        long long c1=0,c2=0;
        for(int i=0;i<nums.size();i++){
            int it=nums[i];
            if(x<it){
                c1+=it;
                x=it;
            }
            if(i>=t&&y>=it){
                c2+=it;
                y=it;
            }
        }
        // cout<<c1<<" "<<c2<<endl;
        return (c1==c2)?-1:(c2>c1);
    }
};