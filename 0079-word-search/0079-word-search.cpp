class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    
    bool helper(vector<vector<char>>& board, string &word, int ind, int i, int j) {
        if(ind == word.length())
            return true;

        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$')
            return false;

        if(board[i][j] != word[ind])
            return false;

        char temp = board[i][j];
        board[i][j] = '$';  // mark visited

        for(auto &dir : directions) {
            if(helper(board, word, ind + 1, i + dir[0], j + dir[1])) {
                board[i][j] = temp;  // restore before return
                return true;
            }
        }

        board[i][j] = temp;  // restore
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;

        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0] && helper(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};
