// Last updated: 10/27/2025, 7:10:32 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string sample=strs[0];
        string se="";
        int i=0,count=0;
        char ch=sample[0];
            for(int j=0;i<sample.size()&&j<strs.size();j++){
                if(ch==strs[j][i]){
                    count++;
                }
                if(count==strs.size()){
                    se+=sample[i];
                    i++;
                    j=-1;
                    count=0;
                    if(i<sample.size()) ch=sample[i];
                }
                else if(j==strs.size()-1) return se; 
            }
        return se;
    }
};