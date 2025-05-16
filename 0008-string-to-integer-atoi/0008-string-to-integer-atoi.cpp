class Solution {
public:
    int myAtoi(string s) {
        int i = 0; // Pointer for traversing the string
        int n = s.size(); // Length of the string
        
        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Handle empty string after trimming spaces
        if (i >= n) return 0;

        // Step 3: Determine the sign of the number
        int sign = 1; // Default is positive
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        
        long ans = 0; // To store the result as we process digits

        // Step 4: Convert numeric characters to integer
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0'; // Convert character to integer
            
            // Check for overflow/underflow BEFORE updating `ans`
            if (ans > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            
            ans = ans * 10 + digit; // Update result
            i++;
        }
        
        // Return the final result with the correct sign
        return sign * ans;
    }
};