// Last updated: 15/04/2026, 00:44:50
class Solution {
public:
    string decodeCiphertext(string enc, int n) {
        int k=enc.size();
        int m=k/n;
        string ans="";
        for(int j=0;j<m;j++){
            string temp="";
            int x=0;
            for(int i=0;i<n;i++){
                if(j+i*m+x<k) temp+=enc[j+i*m+x];
                x++;
            }
            ans+=temp;
        }
        ans.erase(ans.find_last_not_of(' ') + 1);
        return ans;
    }
};