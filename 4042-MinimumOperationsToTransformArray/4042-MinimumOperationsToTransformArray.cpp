// Last updated: 10/27/2025, 7:04:44 PM
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        long long base = 0;
        for(int i = 0; i < n; i++) {
            base += abs(nums1[i] - nums2[i]);
        }
         long long minToLast = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            minToLast = min(minToLast, (long long)abs(nums1[i] - nums2[n]));
            minToLast = min(minToLast, (long long)abs(nums2[i] - nums2[n]));
        }
        
        long long ans = 1 + base + minToLast;
        
        for(int i = 0; i < n; i++) {
            long long cost = base - abs(nums1[i] - nums2[i]);
            cost += abs(nums1[i] - nums2[n]);
            
            long long minAppend = abs(nums1[i] - nums2[i]);
            minAppend = min(minAppend, (long long)abs(nums2[n] - nums2[i]));
            
            cost += 1 + minAppend;
            ans = min(ans, cost);
        }
        
        return ans;
    }
};