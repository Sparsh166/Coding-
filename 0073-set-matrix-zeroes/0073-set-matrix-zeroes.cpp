#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();    // Number of rows
        int m = matrix[0].size(); // Number of columns
        
        vector<int> row(n, 0);  // Tracks which rows should be zeroed
        vector<int> col(m, 0);  // Tracks which columns should be zeroed
        
        // Step 1: Identify the rows and columns that need to be zeroed
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        
        // Step 2: Modify the matrix based on row and col arrays
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
