// Last updated: 1/11/2026, 11:09:56 AM
class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++){
            string s=bitset<32>(nums[i]).to_string();
            s=s.substr(s.find('1'));
            reverse(s.begin(), s.end());
            int k=bitset<32>(s).to_ullong();
            vec[i]={k,nums[i]};
        }
        sort(vec.begin(),vec.end());
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            arr[i]=vec[i].second;
        }
        return arr;
    }
};