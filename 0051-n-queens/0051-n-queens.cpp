class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board, int n){
        // upper diagonal check
        int dulrow = row;
        int dulcol = col;

        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            col--;
            row--;
        }
        // left 
        col = dulcol;
        row = dulrow;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        // bottom diagonal
        col = dulcol;
        row = dulrow;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            col--;
            row++;
        }
        return true;
    }
    void helper(int col, int n, vector<string>&board, vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                helper(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board;
        vector<vector<string>>ans;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        helper(0,n,board,ans);
        return ans;
    }
};