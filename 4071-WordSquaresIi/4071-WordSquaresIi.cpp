// Last updated: 1/11/2026, 11:10:16 AM
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        // multiset<string>mp(words.begin(),words.end());
        int n=words.size();
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&words[i][0]==words[j][0]){
                    for(int k=0;k<n;k++){
                        if(k!=i&&k!=j&&words[i][3]==words[k][0]){
                            for(int z=0;z<n;z++){
                                if(z!=i&&z!=j&&z!=k&&words[z][0]==words[j][3]&&words[z][3]==words[k][3]){
                                    ans.push_back({words[i],words[j],words[k],words[z]});
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans.size()<<endl;
        multiset<vector<string>>mp(ans.begin(),ans.end());
        vector<vector<string>>arr(mp.begin(),mp.end());
        return arr;
    }
};