// Last updated: 10/27/2025, 7:06:03 PM
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto &w : words) {
            int i = 0, j = w.size() - 1;
            bool ok = true;
            while (i < j) {
                if (w[i] != w[j]) {
                    ok = false;
                    break;
                }
                i++;
                j--;
            }
            if (ok) return w;
        }
        return "";
    }
};