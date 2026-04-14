// Last updated: 15/04/2026, 00:44:18
class Solution {
public:
    /*
        str1-->n
        str2-->m
        if (str1[i]==T)
            ans[i]...ans[i+m-1]==str2
        else
            ans[i]....ans[i+m-1]!=str2

        i need to return smallest string
        if ans cannot done return {};

        keeping false initally may violate the conditions

        i think first i try keep true cases
        
        ##True case
            if(no ele):
                put str2 to ans
            if(ele):
                check the having ele upto len m if they are same ok then add remaining eles
                if they mismatched return {}
        
        ##False case:
            take a substring from i to len m
            
            if(already having ele mismatched):
                then place all 'a's
            else:
                keep last empty place with lexicographic mismatch ele
                remaning all are a's
        
    */
    bool truecheck(string& ans,string& str,int i){
        int m=str.size();
        int j=0;
        while(j<m){
            if(ans[i+j]!='?'&&ans[i+j]!=str[j]) return false;
            j++;
        }
        j=0;
        while(j<m){
            ans[i+j]=str[j];
            j++;
        }
        return true;
    }

    bool falsecheck(string& ans, string& str, int i) {
        int m=str.size();
        bool mismatch=false;
        for(int j=0;j<m;j++){
            char c=(ans[i+j]=='?')?'a':ans[i+j];
            if(c!=str[j]){
                mismatch=true;
                break;
            }
        }
        if(mismatch){
            return true;
        }
        int j=m-1;
        bool placed=false;
        while(j>=0){
            if(ans[i+j]=='?'){
                if(str[j]=='a') ans[i+j]='b';
                else ans[i+j]='a';
                placed=true;
                break;
            }
            j--;
        }
        if(!placed) return false;
        return true;
    }

    string generateString(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        string ans(m+n-1,'?');
        
        // true case handling
        for(int i=0;i<n;i++){
            if(str1[i]=='T'){
                bool val=truecheck(ans,str2,i);
                if(!val) return {};
            }
        }

        // false case handling
        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
                bool val=falsecheck(ans,str2,i);
                if(!val) return {};
            }
        }
        for(char &c:ans){
            if(c=='?') c='a';
        }
        return ans;
    }
};