class Solution {
public:
    int countTriples(int n) {
        int count = 0;
    for (int c = 1; c <= n; ++c) {
        int c2 = c*c;
        for (int a = 1; a < c; ++a) {
            int b2 = c2 - a*a;
            if (b2 <= 0) continue;
            int b = (int) floor(sqrt((double)b2) + 0.5); // or use integer sqrt trick
            if (1 <= b && b <= n && b*b == b2) {
                ++count;
            }
        }
    }
    return count;
    }
};