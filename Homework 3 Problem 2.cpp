#include <iostream>
#include <cmath>

using namespace std;

void calculation (double a, double b, double c, double &area, double &perimeter)
{
    double s;

    perimeter = (a+b+c);
    s = ((perimeter)/2);

    if (s < 0)
    {
    area = 0;
    perimeter = 0;
    return;
    }

    else if (a > s)
    {
    area = 0;
    perimeter = 0;
    return;
    }

    else if (b > s)
    {
    area = 0;
    perimeter = 0;
    return;
    }

    else if (c > s)
    {
    area = 0;
    perimeter = 0;
    return;
    }  

    area = sqrt(s*(s-a)*(s-b)*(s-c));

}

int main ()
{

    while (true)
    {
        double a,b,c,area,perimeter,s;

        cout << "Enter your length values." << endl;

        cout << "Length 1: ";
        cin >> a;
        if (a < 0)
        {
            break;
        }
        cout << endl;

        cout << "Length 2: ";
        cin >> b;
        if (b < 0)
        {
            break;
        }
        cout << endl;

        cout << "Length 3: ";
        cin >> c;
        if (c < 0)
        {
            break;
        }
        cout << endl;

        calculation (a, b, c, area, perimeter);

        cout << "Area: " << area << endl;
        cout << "Perimeter: " << perimeter << endl;

        if (area == 0)
        {
            break;
        }

        if (perimeter == 0)
        {
            break;
        }

    }

    return 0;

}