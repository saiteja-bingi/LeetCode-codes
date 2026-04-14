// Last updated: 15/04/2026, 00:44:11
class Solution {
public:
    class DSU{
        public:
            vector<int>parent;
            DSU(int n){
                parent.resize(n);
                for(int i=0;i<n;i++) parent[i]=i;
            }
            int find(int x){
                if(parent[x]==x) return x;
                return  parent[x]=find(parent[x]);
            }
            bool unite(int a,int b){
                int pa=find(a);
                int pb=find(b);
                if(pa==pb) return false;
                if(pa!=pb) parent[pa]=pb;
                return true;
            }
    };
    bool possible(int mid,int n,vector<vector<int>>&edges,int k){
        DSU dsu(n);
        int eu=0,uu=0;
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int s=e[2];
            int must=e[3];
            if(must==1&&s<mid) return false;
            if(must==1){
                if(!dsu.unite(u,v)) return false;
                eu++;
            }
        }
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int s=e[2];
            int must=e[3];
            if(must==0&&s>=mid){
                if(dsu.unite(u,v)) eu++;
            }
        }
        for(auto&e:edges){
            int u=e[0];
            int v=e[1];
            int s=e[2];
            int must=e[3];
            if(must==0&&s<mid&&2*s>=mid){
                if(dsu.find(u)!=dsu.find(v) && uu<k){
                    dsu.unite(u,v);
                    eu++;
                    uu++;
                }
            }
        }
        return eu==n-1;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int ms=0;
        for(int i=0;i<edges.size();i++){
            ms=max(ms,edges[i][2]);
        }
        int low=0;
        int high=2*ms;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(mid,n,edges,k)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};