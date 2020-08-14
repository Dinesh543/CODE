Say you have an array for which the i-th element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

solution ::
class Solution {
public:
    int maxProfit(int k, vector<int>& A) {
        int n = A.size();
        if (n == 0 || n == 1) {
            return 0;
        }
        int pro = 0;
        if (n/2 < k) {
            for (int i = 1; i < n; i++) {
                 if (A[i-1] < A[i]) {
                     pro += A[i] - A[i-1];
                }
            }
            return pro;
        }
        vector <vector<int>> profit(k+1,vector<int> (n,0));
        for (int i = 1; i <= k; i++) {
        int prevDiff = INT_MIN;
        for (int j = 1; j < n; j++) {
            prevDiff = max(prevDiff,
                           profit[i - 1][j - 1] - A[j - 1]);
            profit[i][j] = max(profit[i][j - 1],
                               A[j] + prevDiff);
        }
    }

        return profit[k][n-1];
    }
};
