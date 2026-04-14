// Last updated: 15/04/2026, 00:45:14
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>zer(n,0);
        for(int i=0;i<n;i++){
            int j=n-1,c=0;
            while(j>=0&&grid[i][j]==0){
                c++;
                j--;
            }
            zer[i]=c;
        }
        // is it satisfying the constraint/ can i get the one in least distance
        int cost=0;
        for(int i=0;i<n;i++){
            if(zer[i]>=n-i-1){
                continue;
            }
            else{
                int j=i+1;
                for(j=i+1;j<n;j++){
                    if(zer[j]>=n-i-1){
                        break;
                    }
                }
                if(j==n){
                    return -1;
                }
                int num=zer[j];
                cost+=j-i;
                while(j-1>=i){
                    zer[j]=zer[j-1];
                    j--;
                }
                zer[i]=num;
            }
        }
        return cost;
    }
};