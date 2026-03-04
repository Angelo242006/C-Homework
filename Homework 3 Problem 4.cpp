#include <iostream>
#include <cmath>

using namespace std;

void inputlbs (double &weightlbs)
{
    cout << "What is your weight in lbs?" << endl;
    cin >> weightlbs;
    cout << endl;
}

void inputoz (double &weightoz)
{
    cout << "What is the rest of your weight in oz?" << endl;
    cin >> weightoz;
    cout << endl;
}

void convert (double weightlbs, double weightoz, double weightkg, double weightg)
{
    weightkg = (weightlbs / 2.0245);
    weightg = ((weightkg - round(weightkg)) * 1000) + (weightoz * 28.3495);

    cout << "Your weight is: " << weightkg << " kg and " << weightg << " g." << endl;
}


int main ()
{
    double weightlbs;
    double weightoz;
    double weightkg;
    double weightg;

    while (true)
    {

    inputlbs (weightlbs);
    inputoz (weightoz);
    convert (weightlbs, weightoz, weightkg, weightg);

    }

    return 0;
}