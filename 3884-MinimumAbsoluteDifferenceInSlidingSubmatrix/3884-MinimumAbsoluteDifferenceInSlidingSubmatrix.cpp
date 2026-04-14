// Last updated: 15/04/2026, 00:44:13
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        // set,unmap
        int n=grid.size();
        int m=grid[0].size();
        int r=n-k+1,c=m-k+1;
        vector<vector<int>>ans(r);
        for(int i=0;i<r;i++){
            set<int>st;
            unordered_map<int,int>mp;

            for(int j=i;j<i+k;j++){
                for(int l=0;l<k;l++){
                    st.insert(grid[j][l]);
                    mp[grid[j][l]]++;
                }
            }

            auto getDiff = [&]() {
                if(st.size() <= 1) return 0;
                int diff = INT_MAX;
                auto it = next(st.begin());
                while(it != st.end()) {
                    diff = min(diff, *it - *prev(it));
                    it++;
                }
                return diff;
            };

            ans[i].push_back(getDiff());

            for(int j=1;j<c;j++){
                for(int l=i;l<i+k;l++){
                    mp[grid[l][j-1]]--;
                    if(mp[grid[l][j-1]]==0){
                        st.erase(grid[l][j-1]);
                    }
                }
                for(int l=i;l<i+k;l++){
                    st.insert(grid[l][j+k-1]);
                    mp[grid[l][j+k-1]]++;
                }
                ans[i].push_back(getDiff());
            }
        }
        return ans;
    }
};