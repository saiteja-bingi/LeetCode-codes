// Last updated: 15/04/2026, 00:45:40
class Solution {
public:
    /*
        observations:
        -2 move chnage direction to left
        N->W,S->E,E->N,W->S
        -1 change direction to rigth
        N-E, E-S, S->W,W->N

        dir%2==0:
            // means it is in x axis
            // i need to check in y fixed
            mp[y]->first ele that is <=curx+units


        //(n,1),(s,-1),(e,2),(w,-2)
    */

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n=commands.size();
        map<pair<int,int>,int>mp;
        for(auto vec:obstacles){
            mp[{vec[0],vec[1]}]++;
        }
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int ans=0,x=0,y=0;
        int dir=0;
        for(auto it:commands){
            if(it==-1){
                dir=(dir+1)%4;
            }
            else if(it==-2){
                dir=(dir+3)%4;
            }
            else{
                for(int i=0;i<it;i++){
                    int nx=x+dx[dir];
                    int ny=y+dy[dir];
                    if(mp.count({nx,ny})) break;
                    x=nx;
                    y=ny;
                    ans=max(ans,x*x+y*y);
                }
            }
        }
        return ans;
        
    }
};