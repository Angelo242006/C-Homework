#include <iostream>
using namespace std;

int main()
{

    // Requesting the size of the array.
    int n;

    cout << "What is the size of the array: " << endl;
    cin >> n;
    cout << endl;

    // Declaring the array with its size.
    int integers[n];

    // Asking the user for integers that are inserted within the array (breaks if non negative).

    int number;

    for (int i = 0; i < n; i++)
    {

        cout << "What is the positive integer value?" << endl;
        cin >> number;

        if (number < 0)
        {
            break;
        }

        integers[i] = number;

        cout << endl;  
    }

    // Determining the maximum number of bins.

    int max = integers[0];
    for (int i = 0; i < n; i++)
    {
        if (integers[i] > max)
        {
            max = integers[i];
        }
    }

    int maxbins = (max / 10) + 1;

    // List of bins and the number of values that fall into each bin.

    int bins[maxbins];

    for (int i = 0; i < maxbins; i++)
    {
        bins[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int bin = integers[i] / 10;
        bins[bin]++;
    }

    for (int i = 0; i < maxbins; i++)
    {
        cout << i*10 << "-" << i*10 + 9 << ": " << bins[i] << endl;
    }

   return 0;

}