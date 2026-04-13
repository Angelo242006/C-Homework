#include <iostream>
using namespace std;

class PrimeNumber
{
private:
    int prime;

    bool isPrime(int num)
    {
        if (num <= 1)
            return false;

        for (int i = 2; i <= num / 2; i++)
        {
            if (num % i == 0)
                return false;
        }

        return true;
    }

public:
    PrimeNumber() { prime = 1; }

    PrimeNumber(int p)
    {
        if (isPrime(p))
            prime = p;
        else
            prime = 1;
    }

    int getPrime() const
    {
        return prime;
    }

    PrimeNumber operator++()
    {
        int nextPrime = prime + 1;

        while (!isPrime(nextPrime))
        {
            nextPrime++;
        }

        prime = nextPrime;
        return PrimeNumber(prime);
    }

    PrimeNumber operator++(int)
    {
        PrimeNumber temp(prime);

        int nextPrime = prime + 1;
        while (!isPrime(nextPrime))
        {
            nextPrime++;
        }

        prime = nextPrime;

        return temp;
    }

    PrimeNumber operator--()
    {
        int prevPrime = prime - 1;

        while (prevPrime > 1 && !isPrime(prevPrime))
        {
            prevPrime--;
        }

        prime = prevPrime;
        return PrimeNumber(prime);
    }

    PrimeNumber operator--(int)
    {
        PrimeNumber temp(prime);

        int prevPrime = prime - 1;
        while (prevPrime > 1 && !isPrime(prevPrime))
        {
            prevPrime--;
        }

        prime = prevPrime;

        return temp;
    }
};

int main()
{
    PrimeNumber p1;
    cout << "Default prime: " << p1.getPrime() << endl;

    PrimeNumber p2(13);
    cout << "Start prime: " << p2.getPrime() << endl;

    PrimeNumber p3 = ++p2;
    cout << "Prefix ++ : " << p3.getPrime() << endl;
    cout << "p2 is now: " << p2.getPrime() << endl;

    PrimeNumber p4 = p2++;
    cout << "Postfix ++ : " << p4.getPrime() << endl;
    cout << "p2 is now: " << p2.getPrime() << endl;

    PrimeNumber p5 = --p2;
    cout << "Prefix -- : " << p5.getPrime() << endl;
    cout << "p2 is now: " << p2.getPrime() << endl;

    PrimeNumber p6 = p2--;
    cout << "Postfix -- : " << p6.getPrime() << endl;
    cout << "p2 is now: " << p2.getPrime() << endl;

    return 0;
}