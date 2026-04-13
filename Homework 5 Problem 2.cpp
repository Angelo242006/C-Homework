#include <iostream>
#include <string>
using namespace std;

class Pizza
{
private:
    int typeassign;
    int sizeassign;
    int cheeseToppings;
    int pepperoniToppings;

public:
    static const int DEEP_DISH = 1;
    static const int HAND_TOSSED = 2;
    static const int PAN = 3;

    static const int SMALL = 1;
    static const int MEDIUM = 2;
    static const int LARGE = 3;

    Pizza()
    {
        typeassign = DEEP_DISH;
        sizeassign = SMALL;
        cheeseToppings = 0;
        pepperoniToppings = 0;
    }

    void set_type(int x)
    {
        typeassign = x;
    }

    void set_size(int y)
    {
        sizeassign = y;
    }

    void set_toppings(int z, int a)
    {
        cheeseToppings = z;
        pepperoniToppings = a;
    }

    string get_type()
    {

        if (typeassign == DEEP_DISH)
        {
            return "Deep Dish";
        }
        else if (typeassign == HAND_TOSSED)
        {
            return "Hand Tossed";
        }
        else if (typeassign == PAN)
        {
            return "Pan";
        }

        return "Unknown Type";
    }

    string get_size()
    {

        if (sizeassign == SMALL)
        {
            return "Small";
        }
        else if (sizeassign == MEDIUM)
        {
            return "Medium";
        }
        else if (sizeassign == LARGE)
        {
            return "Large";
        }

        return "Unknown Size";
    }

    int get_cheese_toppings()
    {
        return cheeseToppings;
    }

    int get_pepperoni_toppings()
    {
        return pepperoniToppings;
    }

    double computePrice()
    {
        int totalToppings = cheeseToppings + pepperoniToppings;

        if (sizeassign == SMALL)
        {
            return 10 + (2 * totalToppings);
        }
        else if (sizeassign == MEDIUM)
        {
            return 14 + (2 * totalToppings);
        }
        else if (sizeassign == LARGE)
        {
            return 17 + (2 * totalToppings);
        }

        return 0;
    }

    void outputDescription()
    {
        cout << "Here is your final pizza:\n" << endl;
        cout << get_size() << " " << get_type() << " Pizza" << endl;
        cout << "Cheese toppings: " << get_cheese_toppings() << endl;
        cout << "Pepperoni toppings: " << get_pepperoni_toppings() << endl;
    }
};

int main()
{
    int x, y, z, a;

    cout << "Here is the menu:\n";
    cout << "1. Deep Dish\n2. Hand Tossed\n3. Pan" << endl;
    cout << "Which number pizza would you like?" << endl;
    cin >> x;
    cout << endl;

    cout << "Great choice! Now, what size pizza would you like?\n";
    cout << "1. Small\n2. Medium\n3. Large" << endl;
    cin >> y;
    cout << endl;

    cout << "Nice, now let's talk toppings.\nHow many cheese toppings?" << endl;
    cin >> z;
    cout << endl;

    cout << "How many pepperoni toppings?" << endl;
    cin >> a;
    cout << endl;

    Pizza pizza1;
    pizza1.set_type(x);
    pizza1.set_size(y);
    pizza1.set_toppings(z, a);

    pizza1.outputDescription();
    cout << "Price: $" << pizza1.computePrice() << endl;

    cout << "\nAnother pizza example:\n" << endl;

    Pizza pizza2;
    pizza2.set_type(Pizza::HAND_TOSSED);
    pizza2.set_size(Pizza::LARGE);
    pizza2.set_toppings(1, 2);

    pizza2.outputDescription();
    cout << "Price: $" << pizza2.computePrice() << endl;

    return 0;
}