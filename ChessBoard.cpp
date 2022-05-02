#include <iostream>

using namespace std;

//Declared constant here to make it easy to change.
const int N = 5;

void printBoard(const int[N][N]);
bool isValid(const int[N][N], int, int);
bool placeQueens(int[N][N], int);
bool organiseBoard();

int main()
{
    organiseBoard();

    return 0;
}


void printBoard(const int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(const int board[N][N], int rows, int col)
{
    for (int i = 0; i < N; i++)
        if (board[rows][i])
            return false;
    for (int i = rows, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (int i = rows, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
}

bool placeQueens(int board[N][N], int col)
{
    if (col >= N)
        return true;

    for(int i = 0; i < N; i++)
        if (isValid(board, i, col))
        {
            board[i][col] = 1;

            if (placeQueens(board, col + 1))
                return true;

            board[i][col] = 0;
        }
}

bool organiseBoard()
{
    int board[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (!placeQueens(board, 0))
    {
        cout << "Not possible for " << N << " queens on a board that is "
             << N << " rows by " << N << " columns.\n";

        return false;
    }

    printBoard(board);

    return true;
}
