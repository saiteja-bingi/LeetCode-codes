// Last updated: 10/27/2025, 7:05:41 PM
class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        map<int,int>mp;
        long long score =0;
        int n=values.size();
        for(long long i=0;i<n;){
            if(i<0||i>=n||mp.find(i)!=mp.end()) return score;
            if(instructions[i]=="add"){
                score+=values[i];
                mp[i]++;
                i++;
            }
            else if(instructions[i]=="jump"){
                mp[i]++;
                i=i+values[i];
            }
        }
        return score;
    }
};