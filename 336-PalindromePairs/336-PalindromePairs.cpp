// Last updated: 15/04/2026, 00:46:38
class Solution {
public:

    bool ispal(string& s, int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;r--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>ans;

        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]=i;
        }
        int n=words.size();
        for(int i=0;i<n;i++){
            int m=words[i].size();
            string word=words[i];
            for(int j=0;j<=m;j++){
                string left=word.substr(0,j);
                string right=word.substr(j);
                if(ispal(word,0,j-1)){
                    string r=string(right.rbegin(),right.rend());
                    if(mp.count(r)){
                        // for(auto x:mp[r]){
                            int x=mp[r];
                            if(i!=x) ans.push_back({x,i});
                        // }
                    }
                }
                if(j!=m&&ispal(word,j,m-1)){
                    string l=string(left.rbegin(),left.rend());
                    if(mp.count(l)){
                        // for(auto x:mp[l]){
                             int x=mp[l];
                            if(i!=x) ans.push_back({i,x});
                        // }
                    }
                }
            }
            
        }
        return ans;
    }
};