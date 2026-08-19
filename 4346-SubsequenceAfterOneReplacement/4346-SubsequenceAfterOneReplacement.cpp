// Last updated: 19/8/2026, 11:58:14 pm
class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        if(n>m) return  false;
        if(n==1) return true;
        int i=0,j=0;
        vector<int>a1(n,-1),a2(n,-1);
        while(i<n&&j<m){
            while(j<m&&s[i]!=t[j]) j++;
            if(j<m) a1[i]=j;
            i++;
            j++;
        }
        i=n-1;j=m-1;
        while(i>=0&&j>=0){
            while(j>=0&&s[i]!=t[j]) j--;
            if(j>=0) a2[i]=j;
            i--;
            j--;
        }
        if(a2[1]!=-1&&a2[1]!=0||a1[n-2]!=-1&&a1[n-2]!=m-1) return true;
        for(int i=1;i<n-1;i++){
            if(a1[i-1]!=-1&&a2[i+1]!=-1&&a2[i+1]-a1[i-1]-1>=1) return true;
        }
        return false;
    }
};

/*
    chnage one to bbecome sub sequence
    
*/