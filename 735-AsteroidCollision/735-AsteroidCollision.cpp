// Last updated: 10/27/2025, 7:06:43 PM
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return {};
        stack<int>s;
        s.push(nums[0]);
        for(int i=1;i<n;i++){
            bool add=1;
            int curr=nums[i];
            while(!s.empty()&&(s.top()>0&&curr<0)){
                if(abs(curr)==abs(s.top())){
                    s.pop();
                    add=0;
                    break;
                }
                else if (abs(curr)>abs(s.top())){
                    s.pop();
                }
                else{
                    add=false;
                    break;
                }
            }
            if(add) s.push(curr);
        }
        int m=s.size();
        vector<int>ans(m);
        for(int i=m-1;i>=0;i--){
            ans[i]=s.top();
            s.pop();
        }
        return ans;
    }
};