#include <iostream>
using namespace std;

// Picking seat function
void pickseat(int &number, char &seat, char isle[10][4])
{
    // Picking the isle number
    cout << "Which number isle?" << endl;
    cin >> number;
    while ((number < 1) || (number > 10))
    {
        cout << "Sorry that is not an available row number, please choose between isles 1 - 10." << endl;
        cin >> number;
    }

    // Picking the seat letter
    cout << "Would you like seat A, B, C, or D?" << endl;
    cin >> seat;
    while ((seat != 'A') && (seat != 'B') && (seat != 'C') && (seat != 'D') &&
           (seat != 'a') && (seat != 'b') && (seat != 'c') && (seat != 'd'))
    {
        cout << "Sorry that is not an available seat letter, please choose between seats A, B, C, and D." << endl;
        cin >> seat;
    }

    if (seat == 'a')
    {
        seat = 'A';
    }
    if (seat == 'b')
    {
        seat = 'B';
    }
    if (seat == 'c')
    {
        seat = 'C';
    }
    if (seat == 'd')
    {
        seat = 'D';
    }

    while (((seat == 'A') && (isle[number - 1][0] == 'X')) ||
           ((seat == 'B') && (isle[number - 1][1] == 'X')) ||
           ((seat == 'C') && (isle[number - 1][2] == 'X')) ||
           ((seat == 'D') && (isle[number - 1][3] == 'X')))
    {
        cout << "Sorry that seat is not available, pick another seat please." << endl;

        cout << "Which number isle?" << endl;
        cin >> number;
        while ((number < 1) || (number > 10))
        {
            cout << "Sorry that is not an available row number, please choose between isles 1 - 10." << endl;
            cin >> number;
        }

        cout << "Would you like seat A, B, C, or D?" << endl;
        cin >> seat;
        while ((seat != 'A') && (seat != 'B') && (seat != 'C') && (seat != 'D') &&
               (seat != 'a') && (seat != 'b') && (seat != 'c') && (seat != 'd'))
        {
            cout << "Sorry that is not an available seat letter, please choose between seats A, B, C, and D." << endl;
            cin >> seat;
        }

        if (seat == 'a')
        {
            seat = 'A';
        }
        if (seat == 'b')
        {
            seat = 'B';
        }
        if (seat == 'c')
        {
            seat = 'C';
        }
        if (seat == 'd')
        {
            seat = 'D';
        }
    }
}

// Updating the pattern post - pick
void updatepattern(int &number, char &seat, char isle[10][4])
{
    if (seat == 'A')
    {
        isle[number - 1][0] = 'X';
    }
    else if (seat == 'B')
    {
        isle[number - 1][1] = 'X';
    }
    else if (seat == 'C')
    {
        isle[number - 1][2] = 'X';
    }
    else if (seat == 'D')
    {
        isle[number - 1][3] = 'X';
    }

    for (int j = 0; j < 10; j++)
    {
        cout << j + 1 << " ";
        for (int i = 0; i < 4; i++)
        {
            cout << isle[j][i] << " ";
        }
        cout << endl;
    }
}

bool fullplane(char isle[10][4])
{
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (isle[j][i] != 'X')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int number;
    char seat;
    string answer;

    char isle[10][4] =
    {
        {'A','X','C','D'},
        {'A','B','C','D'},
        {'A','B','C','X'},
        {'A','B','C','D'},
        {'X','B','C','D'},
        {'A','B','C','D'},
        {'A','B','C','D'},
        {'A','B','C','D'},
        {'A','B','C','D'},
        {'A','B','C','D'}
    };

    // Establshing the view of all seats
    cout << "Here are your available seat choices!" << endl;

    for (int j = 0; j < 10; j++)
    {
        cout << j + 1 << " ";
        for (int i = 0; i < 4; i++)
        {
            cout << isle[j][i] << " ";
        }
        cout << endl;
    }

    // Picking the new seat
    cout << "Hello! Which seat would you like today?" << endl;
    cout << "\n";
    pickseat(number, seat, isle);

    // Updating the pattern of the seating
    updatepattern(number, seat, isle);

    // Asking the user if they would like a new seat
    while (true)
    {
        if (fullplane(isle))
        {
            cout << "All seats are taken." << endl;
            return 0;
        }

        cout << "Would you like another seat?" << endl;
        cin >> answer;

        if ((answer == "no") || (answer == "No") || (answer == "NO"))
        {
            return 0;
        }
        if ((answer == "yes") || (answer == "Yes") || (answer == "YES"))
        {
            pickseat(number, seat, isle);
            updatepattern(number, seat, isle);
        }
        else
        {
            return 0;
        }
    }

    return 0;
}
