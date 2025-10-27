// Last updated: 10/27/2025, 7:06:49 PM
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int>mp;
        int count=0;
        for(auto it:answers){
            if(it==0) count++;
            else if(mp.find(it)==mp.end()){
                count+=1+it;
            }
            else if(mp[it]==it+1){
                count+=1+it;
                mp[it]=0;
            }
            mp[it]++;
        }
        return count;
    }
};