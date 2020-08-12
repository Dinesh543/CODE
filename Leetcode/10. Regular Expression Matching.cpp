Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Note:

    s could be empty and contains only lowercase letters a-z.
    p could be empty and contains only lowercase letters a-z, and characters like . or *.

Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false

solution::

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> t(n+1,vector<bool>(m+1,false));
        t[0][0] = true;
        for (int j = 1; j <= m; j++) {
            if (p[j-1] == '*' ) {
                   t[0][j] = t[0][j-2];
            } else {
                t[0][j] = false;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    t[i][j] = t[i-1][j-1];
                }
                else if (j > 1 && p[j-1] == '*') {
                    if (t[i][j-2] == 1)
                        t[i][j] = 1;
                    if (s[i-1] == p[j-2] || p[j-2] == '.')
                        if (t[i-1][j] == 1)
                            t[i][j] = t[i-1][j];
                }else  {
                    t[i][j] = false;
                }
            }
        }
        return t[n][m];
    }
};
