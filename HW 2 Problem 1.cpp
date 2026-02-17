#include <iostream>
#include <cmath>


using namespace std;


float gconstant = 6.673e-11;


int main (){


   int end = 0;
   string x;
   double F;
   double mass1;
   double mass2;
   double distance;   
  
   while (end == 0){


       cout << "What is the first mass (in KG)?" << endl;
       cin >> mass1;
       cout << endl;


       cout << "What is the second mass (in KG)?" << endl;
       cin >> mass2;
       cout << endl;


       cout << "How far are the masses (in CM)?" << endl;
       cin >> distance;
       cout << endl;


       mass1 = (mass1 * 1000);
       mass2 = (mass2 * 1000);
       F = ((gconstant * mass1 * mass2)/(pow(distance, 2.0)));


       cout << "The  gravitational attractive force is " << F << " dynes." << endl;
       cout << "Would you to continue?" << endl;


       cin >> x;


       if (x == "no" || x == "NO"){
            end += 1;
       }


       else{
           end = 0;
       }
   }


   return 0;


}