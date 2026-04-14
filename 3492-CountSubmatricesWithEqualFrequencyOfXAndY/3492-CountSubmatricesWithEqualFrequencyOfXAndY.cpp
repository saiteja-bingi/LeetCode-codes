// Last updated: 15/04/2026, 00:44:25
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<int>pre(m);
        vector<int>isx(m,0);
        int ans=0;
        

        if(arr[0][0]=='X') {pre[0]=1;isx[0]=1;}
        else if(arr[0][0]=='Y') pre[0]=-1;
        else pre[0]=0;
        int c=isx[0];
        for(int i=1;i<m;i++){
            if(arr[0][i]=='X') {
                pre[i]=pre[i-1]+1;
                isx[i]=1;
            }
            else if(arr[0][i]=='Y') pre[i]=pre[i-1]-1;
            else pre[i]=pre[i-1];
            c+=isx[i];
            if(pre[i]==0&&c) {
                ans++;
            }
        }
        for(int i=1;i<n;i++){
            int c=0;
            int xc=0;
            for(int j=0;j<m;j++){
                int k=0;
                if(arr[i][j]=='X') {
                    k++;
                    isx[j]=1;
                }
                else if(arr[i][j]=='Y') k--;
                c+=k;
                xc+=isx[j];
                if((c+pre[j]==0)&&xc){
                    ans++;
                }
                pre[j]+=c;
            }
        }
        return ans;
    }
};