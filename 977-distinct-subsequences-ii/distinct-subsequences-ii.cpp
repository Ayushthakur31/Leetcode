class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> dp(n + 1, 0);
        vector<int> last(26, -1);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {

            char ch = s[i - 1];

            dp[i] = (2 * dp[i - 1]) % MOD;
            if (last[ch - 'a'] != -1) {
                int prev = last[ch - 'a'];

                dp[i] = (dp[i] - dp[prev - 1] + MOD) % MOD;
            }

            last[ch - 'a'] = i;
        }

        return (dp[n] - 1 + MOD) % MOD;
    }
};