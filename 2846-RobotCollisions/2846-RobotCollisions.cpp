// Last updated: 15/04/2026, 00:44:38
class Solution {
public:

    /*
        position,health,direction
        same health then both removed
        high health one survives and health decreased by 1

        sort according to their positions
        R R never colllide R L collide
        R-> <-L R-> only one collion at a time
    */

    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) {
        int n=pos.size();
        vector<vector<int>>vec;

        for(int i=0;i<n;i++){
            int d=1;
            if(dir[i]!='R') d=-1;
            vector<int>tup={pos[i],d,h[i],i};
            vec.push_back(tup);
        }
        sort(vec.begin(),vec.end());

        stack<vector<int>>st;
        int i=0;
        while(i<n){
            auto cur=vec[i];

            if(cur[1]==1){
                st.push(cur);
            }
            else{
                while(!st.empty()&&cur[2]>0&&st.top()[1]==1){
                    auto prev=st.top();
                    st.pop();
                    if(prev[2]<cur[2]){
                        cur[2]--;
                    }
                    else if(prev[2]==cur[2]){
                        cur[2]=0;
                        break;
                    }
                    else{
                        prev[2]--;
                        cur[2]=0;
                        st.push(prev);
                        break;
                    }
                }
                if(cur[2]>0) st.push(cur);
            }
            i++;
        }
        vector<pair<int,int>>p;
        while(!st.empty()){
            auto t=st.top();st.pop();
            p.push_back({t[3],t[2]});
        }
        vector<int>ans;
        sort(p.begin(),p.end());
        for(auto it:p){
            ans.push_back(it.second);
        }
        return ans;

        
        
    }
};