// Last updated: 10/27/2025, 7:10:24 PM
class Solution {
public:
    void function(vector<string>&gp,string &s,int n,int left,int right){
        if(s.size()==2*n){
            gp.push_back(s);
            return;
        }
        if(left<n){
            s.push_back('(');
            function(gp,s,n,left+1,right);
            s.pop_back();
        }
        if(right<left){
            s.push_back(')');
            function(gp,s,n,left,right+1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>gp;
        string s="";
        function(gp,s,n,0,0);
        return gp;
    }
};