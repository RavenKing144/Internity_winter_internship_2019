#include <bits/stdc++.h>
using namespace std;

void printBoard(int n, vector<vector<int>> &board)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]==1) cout << 'Q';
            else cout << ".";
        }
        cout << "\n";
    }
    cout << "\n";
    return;
}

bool isSafe(int n, vector<vector<int>> &board, int row, int col)
{
    int i, j;
    for(i=0;i<col;i++)
    {
        if(board[row][i])
        {
            return false;
        }
    }
    
    for(i=row, j=col;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    
    for(i=row, j=col;j>=0&&i<n;i++, j--)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    
    return true;
}

bool NQueen(int n, vector<vector<int>> &board, int col)
{
    if(col == n)
    {
        printBoard(n, board);
        return true;
    }
    
    bool res = false;
    for(int i=0;i<n;i++)
    {
        if(isSafe(n, board, i, col))
        {
            board[i][col] = 1;
            
            res = NQueen(n, board, col+1) || res;
            
            board[i][col] = 0;
        }
    }
    return res;
}

int main()
{
    int n; // input the number of queens
    cin >> n;
    
    vector<int> c;
    vector<vector<int>> board;
    for(int i=0;i<n;i++)
    {
        c.clear();
        for(int j=0;j<n;j++)
        {
            c.push_back(0);
        }
        board.push_back(c);
    }
    
    if(NQueen(n, board, 0) == false)
    {
        cout << "Solution does not exist.\n";
    }
    else{
        printBoard(n, board);
    }
    return 0;
}