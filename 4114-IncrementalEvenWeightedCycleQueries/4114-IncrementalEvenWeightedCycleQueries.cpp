// Last updated: 08/04/2026, 23:55:31
class Solution {
public:
    /*
        if u and v are two diff components:
            safe to add
        else if they are belongs same component:
            check the parity

    */
    class DSU{
        public:
        vector<int>parent,size,parity;
        DSU(int n){
            parent.resize(n);
            size.resize(n);
            parity.resize(n,0);
            for(int i=0;i<n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }
        pair<int,int> find(int x){
            if(parent[x]==x) return {x,0};
            auto [root,par]=find(parent[x]);
            parent[x]=root;
            parity[x]^=par;
            return {root,parity[x]};
        }
        bool unite(int a,int b,int w){
            auto [root1,p1]=find(a);
            auto [root2,p2]=find(b);
            if(root1==root2){
                return ((p1^p2^w)==0);
            }
            if(size[root1]<size[root2]){
                parent[root1]=root2;
                parity[root1]=p2^p1^w;
                size[root2]+=size[root1];
            }
            else{
                parent[root2]=root1;
                parity[root2]=p1^p2^w;
                size[root1]+=size[root2];
            }
            return true;
        }
    };
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int ans=0;
        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            if(dsu.unite(u,v,w)) ans++;
        }
        return ans;
    }
};