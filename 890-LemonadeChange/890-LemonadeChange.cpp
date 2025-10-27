// Last updated: 10/27/2025, 7:06:38 PM
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5=0,c10=0;
        int n=bills.size();
        // sort(bills.begin(),bills.end());
        if(bills[0]>5) return false;
        for(int i=0;i<n;i++){
            if(bills[i]==5) c5++;
            else if(bills[i]==10){
                c10++;
                if(c5==0) return false;
                c5--;
            }
            else{
                if(c10>=1&&(c5-1)>=0){
                    c10--;
                    c5--;
                }
                else if(c5-3>=0){
                    c5-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};