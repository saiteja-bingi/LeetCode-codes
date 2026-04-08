// Last updated: 08/04/2026, 23:55:02
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s="";
        int n=words.size();
        for(int i=0;i<n;i++){
            string k=words[i];
            int sum=0;
            for(int j=0;j<k.size();j++){
                sum+=weights[k[j]-'a'];
            }
            sum=sum%26;
            s+=(char)('z'-sum);
        }
        return s;
    }
};