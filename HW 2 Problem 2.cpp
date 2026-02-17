#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

int main (){

   double exam1;
   double exam2;
   double exam3;
   double exam4;
   double exam5;

   // Open file for writing
   ofstream write("scores.txt");

   cout << "What is the first exam score?" << endl;
   cin >> exam1;

   cout << "What is the second exam score?" << endl;
   cin >> exam2;


   cout << "What is the third exam score?" << endl;
   cin >> exam3;

   cout << "What is the fourth exam score?" << endl;
   cin >> exam4;

   cout << "What is the fifth exam score?" << endl;
   cin >> exam5;

   write << exam1 << endl;
   write << exam2 << endl;
   write << exam3 << endl;
   write << exam4 << endl;
   write << exam5 << endl;

   write.close();

   // Open file for reading
   ifstream read("scores.txt");

   double a;
   double b;
   double c;
   double d;
   double e;

   read >> a;
   read >> b;
   read >> c;
   read >> d;
   read >> e;

   read.close();

   double average = (a + b + c + d + e) / 5.0;
   double stddev = sqrt((pow(a - average, 2) + pow(b - average, 2) + pow(c - average, 2) + pow(d - average, 2) + pow(e - average, 2)) / 5.0);

   ofstream output("statistics.txt");

   cout << fixed << setprecision(2);
   output << fixed << setprecision(2);

   cout << "Average: " << average << endl;
   cout << "Standard Deviation: " << stddev << endl;

   output << "Average: " << average << endl;
   output << "Standard Deviation: " << stddev << endl;

   output.close();

   return 0;
}