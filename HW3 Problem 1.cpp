#include <iostream>

using namespace std;

void theinput (int &hour, int &minute)
{
    cout << "What is your hour mark?" << endl;
    cin >> hour; 
    if (hour < 0)
    {
        return;
    }
    else if (hour >= 24)
    {
        return;
    }
    cout << endl;

    cout << "What is your minute mark?" << endl;
    cin >> minute;
    if (minute < 0)
    {
        return;
    }
    else if (minute >= 60)
    {
        return;
    }
    cout << endl;
}

void theconversion (int &hour, char &ampm)
{
    if ((hour == 0) || (hour == 24))
    {
        hour = 12;
        ampm = 'A';
    }

    else if (hour < 12)
    {
        ampm = 'A';
    }
    
    else if (hour == 12)
    {
        ampm = 'P';
    }

    else if ((hour > 12) && (hour < 24))
    {
        hour = (hour - 12);
        ampm = 'P';
    }
}

void theoutput (int &hour, int &minute, char &ampm)
{

    cout << "Here is your new time in 24 hour scale: " << hour << ":" << minute << " " << ampm << endl;

}

int main ()
{
    int hour, minute;
    char ampm;

    cout << "You are now putting information in a 24 hour scale." << endl;

    while (true)
    
    {
    theinput(hour, minute);
    if (hour < 0)
    {
        break;
    }
    else if (hour >= 24)
    {
        break;
    }
    if (minute < 0)
    {
        break;
    }
    else if (minute >= 60)
    {
        break;
    }

    theconversion(hour, ampm);
    theoutput (hour, minute, ampm);

    }
    return 0;
}