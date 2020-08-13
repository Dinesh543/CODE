A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).


solution ::

class Solution {
public:
    int numDecodings(string A) {

        if (A.size() == 0 )
        return 0;
        int n = A.size();
        vector <int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = A[0] != '0' ? 1 : 0;
        for (int i = 2; i <= n; i++) {
            int first = D(A.substr(i-1,1));
            int second = D(A.substr(i-2,2));

            if (first > 0 && first<= 9)
                dp[i] += dp[i-1];
            if (second > 9 && second <= 26)
                dp[i] += dp[i-2];
        }
        return dp[n];
}
    int D(string str) {
        int num = 0;
        for (int  i = 0; i < str.size(); i++) {
            num = (num*10) + (str[i]-'0');

        }

    return num;
    }
};

