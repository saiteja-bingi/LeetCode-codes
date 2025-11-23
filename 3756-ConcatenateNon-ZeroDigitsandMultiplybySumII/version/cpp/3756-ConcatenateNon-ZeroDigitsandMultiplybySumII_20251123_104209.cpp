// Last updated: 11/23/2025, 10:42:09 AM
class Solution {
public:
    const long long mod = 1000000007;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> presum(n, 0), premod(n, 0);
        vector<int> precount(n, 0);
        int nzCount = 0;
        for (char c : s) if (c != '0') nzCount++;

        vector<long long> pow(nzCount + 1, 1);
        long long sum = 0, num = 0;
        int nonZeroIndex = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                sum += (s[i] - '0');
                num = (num * 10 + (s[i] - '0')) % mod;
                nonZeroIndex++;
                pow[nonZeroIndex] = (pow[nonZeroIndex - 1] * 10) % mod;
            }
            presum[i] = sum;
            premod[i] = num;
            precount[i] = nonZeroIndex; 
        }

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long digitSum = presum[r] - (l > 0 ? presum[l - 1] : 0);

            long long number = premod[r];
            if (l > 0) {
                int len = precount[r] - precount[l - 1];
                number = (number - premod[l - 1] * pow[len] % mod + mod) % mod;
            }

            ans.push_back((number * digitSum) % mod);
        }

        return ans;
    }
};