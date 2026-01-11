// Last updated: 1/11/2026, 11:09:50 AM
class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n=words.size();
        int m=words[0].size();
        long long c=0;
        map<string,int>mp;
        for(int i=0;i<n;i++){
            string p=words[i];
            bool t=false;
            for(auto &[s,co]:mp){
                int diff=(p[0]-s[0]+26)%26;
                int k=1;
                while(k<m&&((p[k]-s[k]+26)%26==diff)) k++;
                if(k==m){
                    mp[s]++;
                    t=true;
                    break;
                }
            }
            if(!t) mp[p]++;
        }
        for(auto [s,co]:mp){
            cout<<s<<" "<<co<<endl;
        }
        for(auto [s,co]:mp){
            co--;
            c+=(long long)((long long)co*(long long)(co+1)/2);
        }
        
        return c;
    }
};