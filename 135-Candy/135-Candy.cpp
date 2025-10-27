// Last updated: 10/27/2025, 7:09:21 PM
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int sum=1;
        int i=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum++;i++;
                continue;
            }
            int peak=1;
            while(i<n&&ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n&&ratings[i]<ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }
            if(down>peak){
                sum+=down-peak;
            }
        }
        return sum;
    }
};