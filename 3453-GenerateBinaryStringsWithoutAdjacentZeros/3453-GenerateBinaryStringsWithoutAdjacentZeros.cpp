// Last updated: 10/27/2025, 7:05:43 PM
class Solution {
public:
    int r=1;
    void function(vector<string>&bs,string&s,int n){
        if(s.size()==n){
            bs.emplace_back(s);
            return;
        }
        s.push_back('1');
        r=1;
        function(bs,s,n);
        s.pop_back();

        if(!s.empty()&&s.back()!='0'){
            s.push_back('0');
            function(bs,s,n);
            s.pop_back();
        }
        else if(s.size()==0){
            s.push_back('0');
            function(bs,s,n);
            s.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string>bs;
        string s="";
        function(bs,s,n);
        return bs;
    }
};