// Last updated: 10/27/2025, 7:07:10 PM
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            } else {
                return a[0] < b[0];
            }
        });

        int count = 1;
        int i = 1;
        vector<int> ans = {intervals[0][0], intervals[0][1]};

        while(i<n){
            if(i<n&&ans[1]>intervals[i][0]){ 
               
            } 
            else{ 
                ans={intervals[i][0],intervals[i][1]};
                count++;
            }
            i++;
        }
        return n - count;
    }
};
