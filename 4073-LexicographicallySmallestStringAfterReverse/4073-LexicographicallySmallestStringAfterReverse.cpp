// Last updated: 10/27/2025, 7:04:36 PM
class Solution {
public:
    string lexSmallest(string s) {
        int n=s.size();
        string ans=s;
        for(int i=1;i<n;i++){
            string temp=s;
            reverse(temp.begin(),temp.begin()+i+1);
            if(temp<ans){
                ans=temp;
            }
        }
        for(int i=n-2;i>=0;i--){
            string temp=s;
            reverse(temp.begin()+i,temp.end());
            if(temp<ans){
                ans=temp;
            }
        }
        return ans;
    }
};