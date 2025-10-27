// Last updated: 10/27/2025, 7:06:07 PM
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char>st;
        int count=0;
        for(auto it:sentence){
            st.insert(it);
        }
        if(st.size()==26) return true;
        else return false;
    }
};