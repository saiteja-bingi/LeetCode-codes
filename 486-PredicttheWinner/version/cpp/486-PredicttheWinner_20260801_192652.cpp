// Last updated: 1/8/2026, 7:26:52 pm
1class Solution {
2public:
3
4    bool find(auto& nums,int i,int j,int s1,int s2,bool c){
5        if(j<i){
6            return s1>=s2;
7        }
8        bool ans=false;
9        if(!c){
10            ans=find(nums,i+1,j,s1+nums[i],s2,!c)||find(nums,i,j-1,s1+nums[j],s2,!c);
11        }
12        else{
13            ans=find(nums,i+1,j,s1,s2+nums[i],!c)&&find(nums,i,j-1,s1,s2+nums[j],!c);
14        }
15        return ans;
16
17    }
18
19    bool predictTheWinner(vector<int>& nums) {
20        return find(nums,0,nums.size()-1,0,0,0);
21    }
22};
23
24