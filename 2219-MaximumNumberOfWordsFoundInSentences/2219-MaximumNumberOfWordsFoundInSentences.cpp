// Last updated: 10/27/2025, 7:06:01 PM
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int count=INT_MIN;
        int n=sentences.size();
        for(int i=0;i<n;i++){
            int c=0;
            for(auto it:sentences[i]){
                if(it==' ') c++;
            }
            c++;
            count=max(count,c);
        }
        return count;
    }
};