// Last updated: 10/27/2025, 7:06:14 PM
#include<cmath>
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int c1=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(abs(arr[i]-arr[j])<=a){
                    for(int k=j+1;k<arr.size();k++){
                        if(abs(arr[j]-arr[k])<=b){
                            if(abs(arr[i]-arr[k])<=c) c1++;
                        }
                    }
                }
            }
        }
        return c1;
    }
};