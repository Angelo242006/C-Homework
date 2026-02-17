#include <iostream>
using namespace std;

int main()
{
   int pick1 = rand() % 25 + 1;
   int pick2 = rand() % 25 + 1;
   int pick3 = rand() % 25 + 1;
   int pick4 = rand() % 25 + 1;

   while (pick2 == pick1)
   {
       pick2 = rand() % 25 + 1;
   }

   while (pick2 == pick1 || pick3 == pick2)
   {
       pick3 = rand() % 25 + 1;
   }

   while (pick4 == pick1 || pick4 == pick2 || pick4 == pick3)
   {
       pick4 = rand() % 25 + 1;
   }

   cout << "The finalist: ";
   cout << pick1 << " " << pick2 << " " << pick3 << " " << pick4 << endl;

   return 0;
}
