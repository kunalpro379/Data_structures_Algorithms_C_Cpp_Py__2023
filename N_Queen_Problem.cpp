#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void addSol(vector<vector<string>>& ans, vector<vector<string>>& board, int n) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string row;
            for (int j = 0; j < n; j++) {
                row += board[i][j];
            }
            temp.push_back(row);
        }
        ans.push_back(temp);
    }

 bool isSafe(int row, int col, vector<vector<string>>& board, int n) {
        int x = row;
        int y = col;

        // Check for the same row
        while (y >= 0) {
            if (board[x][y] == "Q") return false;
            y--;
        }

        // Check for the upper-left diagonal
        x = row;
        y = col;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == "Q") return false;
            y--;
            x--;
        }

        // Check for the lower-left diagonal
        x = row;
        y = col;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == "Q") return false;
            y--;
            x++;
        }

        return true;
    }

    void solve(int row, vector<vector<string>>& ans, vector<vector<string>>& board, int n) {
        if (row == n) {
            addSol(ans, board, n);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = "Q";
                solve(row + 1, ans, board, n);
                board[row][col] = ".";
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n, ".")); 
        vector<vector<string>> ans;

        solve(0, ans, board, n);
        return ans;
    }
};
