Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

solution ::

class Solution {
public:
int lon_common(string A, string B,int n ,int m)
{
    vector<vector<int>> table(n+1,vector<int> (m+1,0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0)
                table[i][j] = j;
            else if (j == 0)
                table[i][j] = i;
            else if (A[i-1] == B[j-1]) {
                table[i][j] = table[i-1][j-1] ;
                } else {
                table[i][j] = 1+ min(table[i-1][j],min(table[i][j-1],
                                                     table[i-1][j-1]));
            }
        }
    }
    return table[n][m];
}

int minDistance(string word1, string word2) {
    return lon_common(word1,word2,word1.size(),word2.size());
    }
};

