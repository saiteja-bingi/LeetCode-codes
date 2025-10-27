// Last updated: 10/27/2025, 7:09:37 PM
class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256]={0};
        int l=0,r=0,minlen=INT_MAX,sindex=-1,count=0;
        int n=s.size();
        for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]]>0) count+=1;
            hash[s[r]]--;
            while(count==t.size()){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sindex=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) count-=1;
                l++;
            }
            r++;
        }
        if(sindex==-1) return "";
        return s.substr(sindex,minlen);
    }
};