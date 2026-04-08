// Last updated: 08/04/2026, 23:55:18
class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans=0;
        int forbid=0;
        for(int bit=31;bit>=0;bit--){
            int testforbid=forbid|(1<<bit);
            bool take=false;
            for(auto &row:grid){
                bool can1=true;
                for(auto& num:row){
                    if((num&testforbid)==0){
                        can1=false;
                        break;
                    }
                }
                if(can1){
                    take=true;
                    break;
                }
            }
            if(take){
                ans|=(1<<bit);
            }
            else{
                forbid=testforbid;
            }
        }
        return ans;
    }
};