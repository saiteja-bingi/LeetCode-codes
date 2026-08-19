// Last updated: 19/8/2026, 11:58:19 pm
class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        vector<vector<int>>ans;
        int i=0,j=0,n=s1.size(),m=s2.size();
        while(i<n&&j<m){
            if(s1[i][0]==s2[j][0]){
                ans.push_back({s1[i][0],s1[i][1]+s2[j][1]});
                i++;
                j++;
                continue;
            }
            if(s1[i][0]>s2[j][0]){
                ans.push_back({s2[j][0],s2[j][1]+s1[i][1]});
                j++;
            }
            else{
                ans.push_back({s1[i][0],s1[i][1]+s2[j][1]});
                i++;
            }
        }
        while(i<n){
            ans.push_back({s1[i][0],s1[i][1]});
            i++;
        }
        while(j<m){
            ans.push_back({s2[j][0],s2[j][1]});
            j++;
        }
        return ans;
    }
};