
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;
// For Show Board of Game..
void ShowBoard();
// For Show Header Of Game.
void ShowHeader();
// For Take Input For Player Turn
void TakeInput();
// CheckRows For Win Or Lose.
bool rowChecker(char symbol);
// Check Column For Win or lose.
bool columnChecker(char symbol);
// check Diagonals For Win Or Lose.
bool diagonalChecker(char symbol);
// Print Out Winner or Loser or Draw.
bool isWinner(char symbol);
// For ClearScreen After Turn.
void clearscreen();
int size = 3, count = 0,DrawCount = 1;
char board[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};
main()
{
    HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(l, 10);
    Sleep(500);
    // This is Funtion of My Header For Tic Tac Toe Game
    ShowHeader();
    HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(m, 9);
    // I Just Print Game Name With This Pattern
    Sleep(1000);
    cout << "                                          T";
    Sleep(300);
    cout << "i";
    Sleep(300);
    cout << "c";
    Sleep(300);
    cout << " T";
    Sleep(300);
    cout << "a";
    Sleep(300);
    cout << "c";
    Sleep(300);
    cout << " T";
    Sleep(300);
    cout << "o";
    Sleep(300);
    cout << "e" << endl;
    HANDLE p = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(p, 6);
    Sleep(500);
    cout << "                                   Developed By Muhammad Danish" << endl;
    HANDLE j = GetStdHandle(STD_OUTPUT_HANDLE);
    Sleep(500);
    SetConsoleTextAttribute(j, 7);
    cout << "                                       Press Any Key To Play" << endl;
    getch();
    Sleep(0);
    system("cls");
    // Take Inputs From User For His Turn..
    TakeInput();
}

void ShowHeader()
{
	cout << "\t    "
         << "_______________________________________________________________________________" << endl;
    cout << "\t    "
         << "_______________________________________________________________________________" << endl
         << endl;
    cout << "\t    "
         << "-------- -------- -------   -------- ------- -------   -------- ------- -------" << endl;
    cout << "\t    "
         << "-------- -------- ||-----   -------- |-----| ||-----   -------- ||---|| ||     " << endl;
    cout << "\t    "
         << "   ||       ||    ||           ||    ||   || ||           ||    ||   || -----  " << endl;
    cout << "\t    "
         << "   ||       ||    ||           ||    ||---|| ||           ||    ||   || -----  " << endl;
    cout << "\t    "
         << "   ||    -------- ||-----      ||    ||---|| ||-----      ||    ||---|| ||     " << endl;
    cout << "\t    "
         << "   ||    -------- -------      ||    ||   || -------      ||    ------- -------" << endl
         << endl;
    cout << "\t    "
         << "_______________________________________________________________________________" << endl;
    cout << "\t    "
         << "_______________________________________________________________________________" << endl;
    cout << endl;
}
void ShowBoard()
{
    ShowHeader();
    cout << "\t\t\t\t\t"
         << "      0     1     2   " << endl;
    cout << "\t\t\t\t\t"
         << "   ___________________" << endl;
    cout << "\t\t\t\t\t"
         << "   |     |     |     |" << endl;
    cout << "\t\t\t\t\t"
         << "A"
         << "  |  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  | " << endl;

    cout << "\t\t\t\t\t"
         << "   |_____|_____|_____|" << endl;
    cout << "\t\t\t\t\t"
         << "   |     |     |     |" << endl;

    cout << "\t\t\t\t\t"
         << "B"
         << "  |  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  | " << endl;

    cout << "\t\t\t\t\t"
         << "   |_____|_____|_____|" << endl;
    cout << "\t\t\t\t\t"
         << "   |     |     |     |" << endl;

    cout << "\t\t\t\t\t"
         << "C"
         << "  |  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  | " << endl;

    cout << "\t\t\t\t\t"
         << "   |_____|_____|_____|" << endl
         << endl;
}

void clearscreen()
{
    cout << endl;
    cout << "Press any key to continue...";
    getch();
    system("cls");
}
bool rowChecker(char symbol)
{
    int count = 0;
    for (int row = 0; row < size; row++)
    {
        count = 0;
        for (int col = 0; col < size; col++)
        {
            if (board[row][col] == symbol)
            {
                count = count + 1;
            }
        }
        if (count == size)
        {
            return 1;
        }
    }
    return 0;
}

bool columnChecker(char symbol)
{

    int count = 0;
    for (int col = 0; col < size; col++)
    {
        count = 0;
        for (int row = 0; row < size; row++)
        {
            if (board[row][col] == symbol)
            {
                count = count + 1;
            }
        }
        if (count == size)
        {
            return 1;
        }
    }
    return 0;
}

bool diagonalChecker(char symbol)
{
    int count = 0;
    for (int row = 0, col = 0; row < size; row++, col++)
    {
        if (board[row][col] == symbol)
        {
            count = count + 1;
        }
        if (count == size)
        {
            return 1;
        }
    }
    count = 0;
    for (int row = 0, col = 2; row < size; row++, col--)
    {
        if (board[row][col] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == size)
    {
        return 1;
    }
    return 0;
}

bool isWinner(char symbol)
{
    if (rowChecker(symbol) || columnChecker(symbol) || diagonalChecker(symbol))
    {
        return 1;
    }

    return 0;
}

void TakeInput()
{
    string input;
    int row, col;
    char player;
    while (true)
    {
        ShowBoard();
        if (DrawCount % 2 != 0)
        {
            cout << "Player1'X turn..... " << endl;
        }
        if (DrawCount % 2 == 0)
        {
            cout << "Player2'O turn..... " << endl;
        }

        cout << "Enter Your Square like(A0) : ";
        cin >> input;

        if (input == "A0")
        {
            row = 0, col = 0;
        }
        else if (input == "A1")
        {
            row = 0, col = 1;
        }
        else if (input == "A2")
        {
            row = 0, col = 2;
        }
        else if (input == "B0")
        {
            row = 1, col = 0;
        }
        else if (input == "B1")
        {
            row = 1, col = 1;
        }
        else if (input == "B2")
        {
            row = 1, col = 2;
        }
        else if (input == "C0")
        {
            row = 2, col = 0;
        }
        else if (input == "C1")
        {
            row = 2, col = 1;
        }
        else if (input == "C2")
        {
            row = 2, col = 2;
        }
        else
        {
            cout << "ERROR! You Enter Wrong Square\nTry Again! :";
            clearscreen();
            TakeInput();
        }
        if (board[row][col] != 'X' && board[row][col] != 'O')
        {
            if (DrawCount % 2 != 0)
            {
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 13);
                board[row][col] = 'X';
            }
            else
            {
                HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(l, 10);
                board[row][col] = 'O';
            }
        }
        else
        {
            cout << "ERROR! You Can Not Over Wright the Place\nTry Again! :";
            clearscreen();
            TakeInput();
        }
        DrawCount++;
        clearscreen();
        ShowBoard();
        system("cls");
        if (isWinner('X'))
        {
            ShowBoard();
            HANDLE m = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(m, 9);
            cout << "\t\t\t\t\t "
                 << "________________________" << endl;
            cout << "\t\t\t\t\t "
                 << "   Player 1 'X Winner    " << endl;
            cout << "\t\t\t\t\t "
                 << "------------------------" << endl;
            clearscreen();
            break;
        }
        if (isWinner('O'))
        {
            ShowBoard();
            HANDLE l = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(l, 5);
            cout << "\t\t\t\t\t "
                 << "________________________" << endl;
            cout << "\t\t\t\t\t "
                 << "   Player 2 'O Winner    " << endl;
            cout << "\t\t\t\t\t "
                 << "------------------------" << endl;
            clearscreen();
            break;
        }
        else
        {
            if (DrawCount == 10)
            {
                ShowBoard();
                HANDLE n = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(n, 10);
                cout << "\t\t\t\t\t "
                     << "  ____________________" << endl;
                cout << "\t\t\t\t\t "
                     << "    Oops! GAME DRAW   " << endl;
                cout << "\t\t\t\t\t "
                     << "  --------------------" << endl;
                clearscreen();
                break;
            }
        }
    }
}
