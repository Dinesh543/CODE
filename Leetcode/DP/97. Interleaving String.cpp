Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

solution ::

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (n + m != s3.size()) {
            return false;
        }
        if (n == 0 && m == 0) {
            if (s3.size() == 0) {
                return true;
            }
            return false;
        }

        vector <vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for (int i = 1; i <= m; i++) {
            if (s1[i-1] == s3[i-1]) {
                dp[0][i] = dp[0][i-1];
            }
        }
        for (int i = 1; i <= n; i++) {
            if (s2[i-1] == s3[i-1]) {
                dp[i][0] = dp[i-1][0];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[j-1] == s3[i+j-1] && s2[i-1] == s3[i+j-1]) {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                } else {
                    if (s1[j-1] == s3[i+j-1]) {
                        dp[i][j] = dp[i][j-1];
                    }
                    if (s2[i-1] == s3[i+j-1]) {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }

        return dp[n][m];
    }
};
