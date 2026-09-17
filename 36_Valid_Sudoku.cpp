class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        for(int i = 0; i < 9; i++) {
            unordered_set<int> s;
            for(int j = 0; j < 9; j++) {
                if(s.count(board[i][j])) {
                    return false;
                }
                else {
                    s.insert(board[i][j]);
                }
            }
        }
        for(int i = 0; i < 9; i++) {
            unordered_set<int> s;
            for(int j = 0; j < 9; j++) {
                if(s.count(board[j][i])) {
                    return false;
                }
                else {
                    s.insert(board[j][i]);
                }
            }
        }

        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {

                unordered_set<int> s;

                for(int r = i; r < i + 3; r++) {
                    for(int c = j; c < j + 3; c++) {

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