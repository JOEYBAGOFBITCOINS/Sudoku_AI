#include <iostream>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;

const int SIZE = 9;
const int EMPTY = 0;

void printBoard(const vector<vector<int>>& board)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (i % 3 == 0 && i != 0)
            cout << "------+-------+------\n";

        for (int j = 0; j < SIZE; j++)
        {
            if (j % 3 == 0 && j != 0)
                cout << "| ";

            if (board[i][j] == 0)
                cout << ". ";
            else
                cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isValid(const vector<vector<int>>& board, int row, int col, int num)
{
    for (int x = 0; x < SIZE; x++)
    {
        if (board[row][x] == num)
            return false;
        if (board[x][col] == num)
            return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

vector<int> getCandidates(const vector<vector<int>>& board, int row, int col)
{
    vector<int> candidates;

    if (board[row][col] != EMPTY)
        return candidates;

    for (int num = 1; num <= 9; num++)
    {
        if (isValid(board, row, col, num))
            candidates.push_back(num);
    }

    return candidates;
}

// MRV heuristic: choose the empty cell with the fewest legal values
bool findMostConstrainedCell(const vector<vector<int>>& board, int& bestRow, int& bestCol)
{
    int minCandidates = 10;
    bool found = false;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == EMPTY)
            {
                vector<int> candidates = getCandidates(board, i, j);
                int count = static_cast<int>(candidates.size());

                if (count < minCandidates)
                {
                    minCandidates = count;
                    bestRow = i;
                    bestCol = j;
                    found = true;

                    if (minCandidates == 1)
                        return true;
                }
            }
        }
    }

    return found;
}

bool solveSudoku(vector<vector<int>>& board)
{
    int row = -1;
    int col = -1;

    if (!findMostConstrainedCell(board, row, col))
        return true; // solved

    vector<int> candidates = getCandidates(board, row, col);

    for (int num : candidates)
    {
        board[row][col] = num;

        if (solveSudoku(board))
            return true;

        board[row][col] = EMPTY; // backtrack
    }

    return false;
}

int main()
{
    vector<vector<int>> board =
{
    {9, 0, 0, 4, 0, 0, 0, 0, 3},
    {0, 4, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 7, 2, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {6, 0, 0, 2, 0, 0, 1, 0, 0},
    {0, 9, 0, 0, 0, 0, 6, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 7, 0, 0, 0, 0, 0, 0, 0},
    {2, 0, 0, 8, 0, 3, 0, 0, 1}
};

    cout << "Starting Sudoku Board:\n";
    printBoard(board);
    cout << "\n";

    if (solveSudoku(board))
    {
        cout << "Solved Sudoku Board:\n";
        printBoard(board);
    }
    else
    {
        cout << "No solution exists.\n";
    }

    return 0;
}