// Last updated: 08/04/2026, 23:54:41
class Solution {
public:
    vector<int>parent,sz;
    int find(int i){
        if(parent[i]==i) return i;
        return parent[i]=find(parent[i]);
    }
    void unite(int i,int j){
        int r1=find(i),r2=find(j);
        if(r1==r2) return;
        if(sz[r1]<sz[r2]) swap(r1,r2);
        sz[r1]+=sz[r2];
        parent[r2]=r1;
    }
    int maxActivated(vector<vector<int>>& p) {
        int n=p.size();
        parent.resize(n);sz.resize(n,1);
        iota(parent.begin(),parent.end(),0);
        unordered_map<int,int>xmp,ymp;
        for(int i=0;i<n;i++){
            if(xmp.count(p[i][0])) unite(i,xmp[p[i][0]]);
            else xmp[p[i][0]]=i;
            if(ymp.count(p[i][1])) unite(i,ymp[p[i][1]]);
            else ymp[p[i][1]]=i;
        }
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                if(sz[i]>c1){
                    c2=c1;c1=sz[i];
                }
                else if(sz[i]>c2){
                    c2=sz[i];
                }
            }
        }
        return c1+c2+1;
    }
};