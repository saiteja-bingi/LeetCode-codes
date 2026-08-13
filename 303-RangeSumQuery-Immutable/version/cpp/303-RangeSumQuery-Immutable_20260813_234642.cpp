// Last updated: 13/8/2026, 11:46:42 pm
1class NumArray {
2public:
3    vector<long long>pre;
4    NumArray(vector<int>& nums) {
5        pre.assign(nums.size()+1,0);
6        for(int i=0;i<nums.size();i++){
7            pre[i+1]=pre[i]+nums[i];
8        }
9    }
10    int sumRange(int left, int right) {
11        return pre[right+1]-pre[left];
12    }
13};
14
15/**
16 * Your NumArray object will be instantiated and called as such:
17 * NumArray* obj = new NumArray(nums);
18 * int param_1 = obj->sumRange(left,right);
19 */