class Solution {
public:
    bool helper(const string &s, int i) {
        if (i >= s.size() / 2) return true;
        if (s[i] != s[s.size() - i - 1]) return false;
        return helper(s, i + 1);
    }

    bool isPalindrome(string s) {
        string clean = "";

        for (char c : s) {
            if (isalnum(c)) {
                clean += tolower(c);
            }
        }

        return helper(clean, 0);
    }
};
