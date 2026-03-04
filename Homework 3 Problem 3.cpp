#include <iostream>
using namespace std;

void thecalculator (int starttime, int endtime, int difference, int hundreds)
{

     hundreds = floor((endtime - starttime) / 100.0);
     difference = endtime - starttime - (40 * hundreds);
     cout << "The difference in time is: " << difference << " minutes." << endl;

}

int main ()
{
    int starttime, endtime, difference, hundreds;

    while (true)
    {

        cout << "You are now inserting time in 24 hour format!" << endl;

        cout << "What is the start time?" << endl;
        cin >> starttime;
        if ((starttime < 0) || (starttime > 2359))
        {
          break;
        }

        cout << "What is the end time?" << endl;
        cin >> endtime;
        if ((endtime < 0) || (endtime > 2359))
        {
           break;
        }

        if (endtime < starttime)
        {
            break;
        }

        thecalculator (starttime, endtime, difference, hundreds);

    }

    return 0;

}
