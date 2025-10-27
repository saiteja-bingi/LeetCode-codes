// Last updated: 10/27/2025, 7:08:44 PM
class Solution {
public:
    void reverse(vector<int>&arr,int st,int en){
        while(st<=en){
            swap(arr[st],arr[en]);
            st++;
            en--;
        }
    }
    void rotate(vector<int>& arr, int k) {
        int n=arr.size();
        k=k%n;
        reverse(arr,0,n-1);
        reverse(arr,0,k-1);
        reverse(arr,k,n-1);
    }
};