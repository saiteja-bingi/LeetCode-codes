// Last updated: 08/04/2026, 23:55:25
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n=words.size();
        map<string,int>mp;
        for(auto &it:words){
            if(it.size()<k) continue;
            cout<<"r"<<endl;
            string m="";
            for(int i=0;i<k;i++){
                m+=it[i];
            }
            cout<<m<<endl;
            mp[m]++;
        }
        int c=0;
        for(auto [x,y]:mp){
            if(y>=2) c++;
        }
        return c;
    }
};