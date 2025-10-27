// Last updated: 10/27/2025, 7:09:49 PM
class Solution {
public:
    struct items{
        int st,ed;
    };
    static bool cond(items a,items b){
        return a.st<b.st;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<items>newarr(n);
        for(int i=0;i<n;i++){
            newarr[i]={intervals[i][0],intervals[i][1]};
        }
        sort(newarr.begin(),newarr.end(),cond);
        int i=1;
        vector<vector<int>>arr;
        int a=newarr[0].st,b=newarr[0].ed;
        while(i<n){
            if(newarr[i].st<=b){
                b=max(b,newarr[i].ed);
            }
            else{
                arr.push_back({a,b});
                a=newarr[i].st;
                b=newarr[i].ed;
            }
            i++;
        }
        arr.push_back({a,b});
        return arr;
    }
};