int Solution::longestValidParentheses(string A) {
    vector <int> dp(A.size()+1,0);
    int res  = 0;
    for (int i = 1; i < A.size(); i++) {
        int j = i-dp[i]-1;
        if (j >=0 && A[j] == '(' && A[i] == ')') {
            dp[i+1] = dp[j] + dp[i] + 2;
        }
        res = max(res,dp[i+1]);
    }
    return res;
}
