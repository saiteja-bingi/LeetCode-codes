// Last updated: 12/7/2026, 10:39:13 pm
1class Solution {
2public:
3    vector<int> arrayRankTransform(vector<int>& arr) {
4        vector<int>temp=arr;
5        int n=arr.size();
6        sort(temp.begin(),temp.end());
7        temp.erase(unique(temp.begin(),temp.end()),temp.end());
8        for(int i=0;i<n;i++){
9            arr[i]=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin()+1;
10        }
11        return arr;
12    }
13};