// Last updated: 12/4/2025, 12:36:26 AM
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string text1 = s;
        reverse(s.begin(), s.end());
        string text2 = s;
        int len1 = text1.length();
        int len2 = text2.length();
        vector<vector<int>> dp(len1, vector<int> (len2, 0));
        // return solve(len1 - 1, len2 - 1, text1, text2, dp);
        if (text1[0] == text2[0]) dp[0][0] = 1;
        for (int i = 1; i < len1; i++) {
            if (text1[i] == text2[0]) dp[i][0] = 1;
            else dp[i][0] = dp[i - 1][0];
        }
        for (int i = 1; i < len2; i++) {
            if (text1[0] == text2[i]) dp[0][i] = 1;
            else dp[0][i] = dp[0][i-1];
        } 
        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {
                if (text1[i] == text2[j]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[len1-1][len2-1];
    }
};