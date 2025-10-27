// Last updated: 10/27/2025, 7:07:44 PM
class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n=nums.size();
        if(n<=k) return "0";
        stack<char>st;
        string ans="";
        for(int i=0;i<n;i++){
            while(k>0&&!st.empty()&&st.top()>nums[i]){
                st.pop();
                k--;
            }
            st.push(nums[i]);
            if(st.size()==1&&st.top()=='0'){
                st.pop();
            }
        }
        while(k>0&&!st.empty()){
            k--;
            st.pop();
        }
        if(st.empty()) return "0";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};