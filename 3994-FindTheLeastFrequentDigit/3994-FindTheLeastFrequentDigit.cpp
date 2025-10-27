// Last updated: 10/27/2025, 7:04:49 PM
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int,int>mp;
        while(n>0){
            int num=n%10;
            mp[num]++;
            n=n/10;
        }
        int num=INT_MAX;
        int rep=INT_MAX;
        for(auto&it : mp){
            if(it.second<rep){
                num=it.first;
                rep=it.second;
            }
            else if(it.second==rep){
                if(it.first<num){
                    num=it.first;
                }
            }
        }
        return num;
    }
};