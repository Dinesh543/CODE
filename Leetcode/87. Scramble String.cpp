Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true

Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false

solution ::

class Solution {
public:
    bool isScramble(string s1, string s2) {
        unordered_map <string,bool> mp;
       return Scram(s1,s2,mp);

    }
    bool Scram(string s1, string s2,unordered_map <string,bool> &mp) {
        if (s1.compare(s2) == 0)
            return true;
        if (s1.size() != s2.size())
            return false;
        if(s1.size() == 0)
            return true;
        string key = s1;
        key.push_back('_');
         key.append(s2);
        if (mp.find(key) != mp.end())
            return mp[key];
        int n= s1.size();
        string copy_S1 = s1, copy_S2 = s2;

    sort(copy_S1.begin(), copy_S1.end());
    sort(copy_S2.begin(), copy_S2.end());

    if (copy_S1 != copy_S2) {
        return false;
    }

        for (int l = 1; l < n; l++){
            if(((Scram(s1.substr(0,l),s2.substr(n-l,l),mp))&&
             (Scram(s1.substr(l,n-l),s2.substr(0,n-l),mp)))||
              ((Scram(s1.substr(0,l),s2.substr(0,l),mp))&&
             (Scram(s1.substr(l,n-l),s2.substr(l,n-l),mp))))
                return true;
        }
        return  false;
    }
};


