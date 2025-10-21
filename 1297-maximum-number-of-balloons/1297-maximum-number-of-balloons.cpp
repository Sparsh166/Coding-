class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // Map to store frequency of characters
        std::map<char, int> freq;

        // Count the frequency of each character in the string
        for (char ch : text) {
            freq[ch]++;
        }

        // Calculate how many times we can form the word "balloon"
        int b = freq['b'];
        int a = freq['a'];
        int l = freq['l'] / 2; // 'l' appears twice in "balloon"
        int o = freq['o'] / 2; // 'o' appears twice in "balloon"
        int n = freq['n'];

        // Return the minimum of all required character counts
        return std::min({b, a, l, o, n});
    }
};
