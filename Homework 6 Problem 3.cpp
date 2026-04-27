#include <iostream>
#include <vector>

using namespace std;

int numberinput ()
{
    int maximumnumber;
    cout << "Insert your integer: " << endl;
    cin >> maximumnumber;

    return maximumnumber;
}

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

vector <int> Erathosthenes (int maximumnumber)
{
    vector <int> numbers;
    for (int i = 2; i <= maximumnumber; i++)
    {
        if (isPrime(i))
        {
            numbers.push_back(i);
        }
    }
    return numbers;
}

int main ()
{
    int N;

    N = numberinput();
    vector <int> numbers = Erathosthenes(N);

    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }

    return 0;
}