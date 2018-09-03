/*
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
*/


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            // refresh map
            map<int, int> rows;
            map<int, int> cols;
            map<int, int> cube;
            for (int j = 0; j < 9; j++) {
            
                // row
                if (board[i][j] != '.') {
                    if (rows.count(board[i][j]) != 0) return false;
                    else rows[board[i][j]]++;
                }
                
                // col
                if (board[j][i] != '.') {
                    if (cols.count(board[j][i]) != 0) return false;
                    else cols[board[j][i]]++;
                }
                
                // cube
                int row_offset = (i/3)*3; // 000 111 222
                int col_offset = (i%3)*3; // 036 036 036 
                if (board[j/3 + row_offset][j%3 + col_offset] != '.') {
                    // 00 - 01 - 02
                    // 10 - 11 - 12
                    // 20 - 21 - 22
                    if (cube.count(board[j/3 + row_offset][j%3 + col_offset]) != 0) return false;
                    else cube[board[j/3 + row_offset][j%3 + col_offset]]++;
                }
            }
        }
        
        return true;
    }
};
