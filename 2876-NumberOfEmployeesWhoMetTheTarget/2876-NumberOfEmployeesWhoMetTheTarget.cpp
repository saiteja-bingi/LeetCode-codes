// Last updated: 10/27/2025, 7:05:45 PM
class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count=0;
        for(auto it:hours){
            if(it>=target) count++;
        }
        return count;
    }
};