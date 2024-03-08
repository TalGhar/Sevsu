#include <iostream>
#include <vector>
#include <catch2/catch_all.hpp>

using namespace std;

class Board
{

private:
    char board[3][3];

public:
    Board()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = '-';
            }
        }
    }

    void printBoard()
    {
        cout << "  1 2 3" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << " ";
            for (int j = 0; j < 3; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool isFull()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '-')
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkWin(char player)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            {
                return true;
            }
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            {
                return true;
            }
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        {
            return true;
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        {
            return true;
        }
        return false;
    }

    bool placeMark(int row, int col, char player)
    {
        if (row >= 0 && row < 3 && col >= 0 && col < 3)
        {
            if (board[row][col] == '-')
            {
                board[row][col] = player;
                return true;
            }
        }
        return false;
    }
};

class Game
{

private:
    char player;
    Board board;

public:
    Game()
    {
        player = 'X';
        board = Board();
    }

    void start()
    {
        cout << "Welcome to Tic Tac Toe!" << endl;
        while (!board.isFull() && !board.checkWin('X') && !board.checkWin('O'))
        {
            board.printBoard();
            int row, col;
            cout << "Player " << player << ", enter row (1-3): ";
            cin >> row;
            cout << "Player " << player << ", enter column (1-3): ";
            cin >> col;
            if (board.placeMark(row - 1, col - 1, player))
            {
                if (player == 'X')
                {
                    player = 'O';
                }
                else
                {
                    player = 'X';
                }
            }
            else
            {
                cout << "Invalid move. Try again." << endl;
            }
        }
        board.printBoard();
        if (board.checkWin('X'))
        {
            cout << "Player X wins!" << endl;
        }
        else if (board.checkWin('O'))
        {
            cout << "Player O wins!" << endl;
        }
        else
        {
            cout << "It's a tie!" << endl;
        }
    }
};

int main()
{
    Game game;
    game.start();
    return 0;
}