#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper to check if a number is numerically balanced
    bool isBalanced(int x) {
        string s = to_string(x);
        vector<int> count(10, 0);
        
        for (char c : s)
            count[c - '0']++;
        
        for (int d = 0; d <= 9; d++) {
            if (count[d] > 0) {
                // Digit 0 can’t be balanced, and count must equal digit
                if (d == 0 || count[d] != d)
                    return false;
            }
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        int x = n + 1;
        while (true) {
            if (isBalanced(x)) {
            return x;
            }
            x++;
        }
    }
};
