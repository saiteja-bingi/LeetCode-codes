// Last updated: 12/7/2026, 10:10:12 pm
class Solution {    // without min heap using map
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> mp;
        int rank = 1;
        for(auto x:temp){
            if(mp.find(x) == mp.end()){
                mp[x] = rank++;
            }
        }

        for(int i=0; i<arr.size(); i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};