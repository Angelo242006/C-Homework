#include <iostream>
using namespace std;

class BicycleSpeedometer
{
    double distance, time, average;

public: 
    void set_distance (double x)
    {
        distance = x;
    }
    void set_time (double y)
    {
        time = (y/60);
    }
    double averagecalculation ()
    {
        average = (distance / time);
        return average;
    }
};

int main ()
{
    double x,y;

    cout << "How many miles did you travel?" << endl;
    cin >> x;

    cout << "How long did it take you to travel that far in minutes?" << endl;
    cin >> y;

    BicycleSpeedometer BicycleSpeedometer1;
    BicycleSpeedometer1.set_distance(x);
    BicycleSpeedometer1.set_time(y);

    cout << "The average speed: " << BicycleSpeedometer1.averagecalculation() << " " << " miles per hour." << endl;

    return 0;
}