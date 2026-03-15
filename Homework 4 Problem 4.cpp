#include <iostream>
using namespace std;

void printboard(char theboard[3][3])
{
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << theboard[j][i] << " ";
        }
        cout << endl;
    }
}

bool available(int &number, char theboard[3][3])
{
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (theboard[j][i] == number + '0')
            {
                return true;
            }
        }
    }
    return false;
}

void choiceupdatex(int &number, char theboard[3][3])
{
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (theboard[j][i] == number + '0')
            {
                theboard[j][i] = 'X';
            }
        }
    }
}

void choiceupdateo(int &number, char theboard[3][3])
{
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (theboard[j][i] == number + '0')
            {
                theboard[j][i] = 'O';
            }
        }
    }
}

bool winnerx(char theboard[3][3])
{
    if ((theboard[0][0] == 'X') && (theboard[0][1] == 'X') && (theboard[0][2] == 'X'))
    {
        return true;
    }
    if ((theboard[1][0] == 'X') && (theboard[1][1] == 'X') && (theboard[1][2] == 'X'))
    {
        return true;
    }
    if ((theboard[2][0] == 'X') && (theboard[2][1] == 'X') && (theboard[2][2] == 'X'))
    {
        return true;
    }

    if ((theboard[0][0] == 'X') && (theboard[1][0] == 'X') && (theboard[2][0] == 'X'))
    {
        return true;
    }
    if ((theboard[0][1] == 'X') && (theboard[1][1] == 'X') && (theboard[2][1] == 'X'))
    {
        return true;
    }
    if ((theboard[0][2] == 'X') && (theboard[1][2] == 'X') && (theboard[2][2] == 'X'))
    {
        return true;
    }

    if ((theboard[0][0] == 'X') && (theboard[1][1] == 'X') && (theboard[2][2] == 'X'))
    {
        return true;
    }
    if ((theboard[0][2] == 'X') && (theboard[1][1] == 'X') && (theboard[2][0] == 'X'))
    {
        return true;
    }

    return false;
}

bool winnero(char theboard[3][3])
{
    if ((theboard[0][0] == 'O') && (theboard[0][1] == 'O') && (theboard[0][2] == 'O'))
    {
        return true;
    }
    if ((theboard[1][0] == 'O') && (theboard[1][1] == 'O') && (theboard[1][2] == 'O'))
    {
        return true;
    }
    if ((theboard[2][0] == 'O') && (theboard[2][1] == 'O') && (theboard[2][2] == 'O'))
    {
        return true;
    }

    if ((theboard[0][0] == 'O') && (theboard[1][0] == 'O') && (theboard[2][0] == 'O'))
    {
        return true;
    }
    if ((theboard[0][1] == 'O') && (theboard[1][1] == 'O') && (theboard[2][1] == 'O'))
    {
        return true;
    }
    if ((theboard[0][2] == 'O') && (theboard[1][2] == 'O') && (theboard[2][2] == 'O'))
    {
        return true;
    }

    if ((theboard[0][0] == 'O') && (theboard[1][1] == 'O') && (theboard[2][2] == 'O'))
    {
        return true;
    }
    if ((theboard[0][2] == 'O') && (theboard[1][1] == 'O') && (theboard[2][0] == 'O'))
    {
        return true;
    }

    return false;
}

bool fullboard(char theboard[3][3])
{
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if ((theboard[j][i] != 'X') && (theboard[j][i] != 'O'))
            {
                return false;
            }
        }
    }
    return true;
}

int main ()
{
    int number;

    char theboard[3][3] =
    {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    cout << "Ready for tic-tac-toe?" << endl;
    printboard(theboard);

    while (true)
    {
        cout << "Player X, what is your number of interest on the board?" << endl;
        cin >> number;
        cout << endl;

        while ((number < 1) || (number > 9) || (available(number, theboard) == false))
        {
            cout << "That is not an available number on the board, please insert an appropriate number" << endl;
            cin >> number;
        }

        choiceupdatex(number, theboard);
        printboard(theboard);

        if (winnerx(theboard) == true)
        {
            cout << "Player X wins!" << endl;
            break;
        }

        if (fullboard(theboard) == true)
        {
            cout << "No more moves are possible." << endl;
            break;
        }

        cout << "Player O, what is your number of interest on the board?" << endl;
        cin >> number;
        cout << endl;

        while ((number < 1) || (number > 9) || (available(number, theboard) == false))
        {
            cout << "That is not an available number on the board, please insert an appropriate number" << endl;
            cin >> number;
        }

        choiceupdateo(number, theboard);
        printboard(theboard);

        if (winnero(theboard) == true)
        {
            cout << "Player O wins!" << endl;
            break;
        }

        if (fullboard(theboard) == true)
        {
            cout << "No more moves are possible." << endl;
            break;
        }
    }

    return 0;
}
