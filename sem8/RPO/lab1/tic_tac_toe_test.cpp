#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

class BoardRefactored
{

private:
    char board[3][3];

    void initializeBoard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = '-';
            }
        }
    }

public:
    BoardRefactored()
    {
        initializeBoard();
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
        bool isWin = false;
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            {
                isWin = true;
            }
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            {
                isWin = true;
            }
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        {
            isWin = true;
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        {
            isWin = true;
        }
        return isWin;
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

TEST_CASE("Board class tests")
{
    Board board = Board();
    BoardRefactored board_refactored = BoardRefactored();
    SUBCASE("Check if the not refactored board is initialized correctly")
    {
        CHECK(board.isFull() == false);
    }
    SUBCASE("Check if the refactored board is initialized correctly")
    {
        CHECK(board_refactored.isFull() == false);
    }
}

TEST_CASE("Checking win tests")
{
    Board board = Board();
    BoardRefactored board_refactored = BoardRefactored();
    board.placeMark(0, 0, 'X');
    board.placeMark(0, 1, 'X');
    board.placeMark(0, 2, 'X');
    board.placeMark(1, 0, 'O');
    board.placeMark(1, 1, 'O');
    board.placeMark(2, 2, 'O');
    SUBCASE("Check not refactored board method to checking win")
    {
        // X X X
        // O O -
        // - - O
        CHECK(board.checkWin('X'));
        CHECK(board.checkWin('O') == false);
    }
    board_refactored.placeMark(0, 0, 'X');
    board_refactored.placeMark(0, 1, 'X');
    board_refactored.placeMark(0, 2, 'X');
    board_refactored.placeMark(1, 0, 'O');
    board_refactored.placeMark(1, 1, 'O');
    board_refactored.placeMark(2, 2, 'O');
    SUBCASE("Check refactored board method to checking win")
    {
        // X X X
        // O O -
        // - - O
        CHECK(board_refactored.checkWin('X'));
        CHECK(board_refactored.checkWin('O') == false);
    }
}