#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {

    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check left diagonal
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check right diagonal
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

void solve(vector<vector<int>>& board, int row, int n) {

    // All queens placed
    if (row == n) {
        cout << "Solution:\n";

        for (auto r : board) {
            for (int x : r)
                cout << x << " ";
            cout << endl;
        }

        cout << endl;
        return;
    }

    // Try every column
    for (int col = 0; col < n; col++) {

        if (isSafe(board, row, col, n)) {

            board[row][col] = 1;

            solve(board, row + 1, n);

            // Backtracking
            board[row][col] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    solve(board, 0, n);

    return 0;
}