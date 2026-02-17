#include <iostream>
using namespace std;

double jacket(double height, double weight, int age);
double waist(double height, double weight, int age);

int main()
{
   double height, weight;
   int age;


   cout << "What is the user's height (in inches)?" << endl;
   cin >> height;


   cout << "What is the user's weight (in lbs)?" << endl;
   cin >> weight;


   cout << "What is the user's age (in years)?" << endl;
   cin >> age;


   double hatsize   = (2.9 * weight) / height;
   double jacketsize = jacket(height, weight, age);
   double waistsize  = waist(height, weight, age);


   cout << "Hat size: " << hatsize <<  " inches." << endl;
   cout << "Jacket size: " << jacketsize <<  " inches." << endl;
   cout << "Waist size: " << waistsize << " inches." << endl;


   return 0;
}


double jacket(double height, double weight, int age)
{
   double jacketsize = (height * weight) / 288.0;


   if (age > 30)
   {
       int decades = (age - 30) / 10;
       jacketsize += decades * (1.0 / 8.0);
   }


   return jacketsize;
}


double waist(double height, double weight, int age)
{
   double waistsize = weight / 5.7;


   if (age > 28)
   {
       int increments = (age - 28) / 2;
       waistsize += increments * (1.0 / 8.0);
   }

   return waistsize;
}