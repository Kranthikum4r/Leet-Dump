class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            unordered_set<int> s;
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                if(s.count(board[i][j])) {
                    return false;
                }
                s.insert(board[i][j]);
            }
        }
        for(int i = 0; i < 9; i++) {
            unordered_set<int> s;
            for(int j = 0; j < 9; j++) {
                if(board[j][i] == '.') continue;
                if(s.count(board[j][i])) {
                    return false;
                }
                s.insert(board[j][i]);
            }
        }

        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {

                unordered_set<int> s;
                for(int r = i; r < i + 3; r++) {
                    for(int c = j; c < j + 3; c++) {
                        if(board[r][c] == '.') continue;
                        
                        if(s.count(board[r][c])) {
                            return false;
                        }
                        s.insert(board[r][c]);
                    }
                }
            }
        }
        return true;
    }
};