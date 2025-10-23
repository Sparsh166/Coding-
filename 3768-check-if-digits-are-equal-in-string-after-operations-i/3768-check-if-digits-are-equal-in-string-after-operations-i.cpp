class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        while (n > 2) {
            string b;
            for (int i = 0; i < n - 1; i++) {
                int value = ( (s[i] - '0') + (s[i + 1] - '0') ) % 10;
                b += ('0' + value);
            }
            s = b;
            n = s.size();
        }
        return s[0] == s[1];
    }
};
