class Solution {
   public:
    bool isRow(vector<vector<char>>& board, int i, int j) {
        for (int start = 0; start < board.size(); start++) {
            if (start != j && board[i][start] == board[i][j]) return false;
        }
        return true;
    }
    bool isCol(vector<vector<char>>& board, int i, int j) {
        for (int start = 0; start < board.size(); start++) {
            if (start != i && board[start][j] == board[i][j]) return false;
        }
        return true;
    }

    bool isBox(vector<vector<char>>& board,
               int row,
               int col) {

        int rowStart = (row / 3) * 3;
        int colStart = (col / 3) * 3;

        for(int i = rowStart;
            i < rowStart + 3;
            i++) {

            for(int j = colStart;
                j < colStart + 3;
                j++) {

                if((i != row || j != col) &&
                   board[i][j] == board[row][col])
                    return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if(board[i][j]=='.') continue;
                else{
                    if(!isRow(board, i,j) || !isCol(board, i,j) || !isBox(board, i,j))return false;
                }
            }
        }
    return true;
    }

};
