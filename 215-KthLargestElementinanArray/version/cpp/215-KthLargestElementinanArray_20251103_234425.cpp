// Last updated: 11/3/2025, 11:44:25 PM
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto it:nums){
            pq.push(it);
        }
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};