#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

class Complex
{
    public:

        double re, im;

        Complex() : re(0.0), im(0.0) {}
        Complex(double r) : re(r), im(0.0) {}
        Complex(double r, double i) : re(r), im(i) {}

        Complex add(const Complex& other) const
        {
            return Complex(re + other.re, im + other.im);
        }   

        Complex subtract(const Complex& other) const
        {
            return Complex(re - other.re, im - other.im);
        }

        Complex multiply(const Complex& other) const
        {
            double realPart = re * other.re - im * other.im;
            double imagPart = re * other.im + im * other.re;
            return Complex(realPart, imagPart);
        }

        Complex divide(const Complex& other) const
        {
            double denominator = other.re * other.re + other.im * other.im;
            double realPart = (re * other.re + im * other.im) / denominator;
            double imagPart = (im * other.re - re * other.im) / denominator;
            return Complex(realPart, imagPart);
        }
};

int calculateMagnitude(const Complex& c)
{
    return sqrt(c.re * c.re + c.im * c.im);
}

int main ()
{
    int Complexsum, Complexdifference, Complexproduct, Complexquotient;

    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);

    Complexsum = calculateMagnitude(c1.add(c2));
    Complexdifference = calculateMagnitude(c1.subtract(c2));
    Complexproduct = calculateMagnitude(c1.multiply(c2));
    Complexquotient = calculateMagnitude(c1.divide(c2));

    cout << "Magnitude of the sum: " << Complexsum << endl;
    cout << "Magnitude of the difference: " << Complexdifference << endl;
    cout << "Magnitude of the product: " << Complexproduct << endl;
    cout << "Magnitude of the quotient: " << Complexquotient << endl;

    return 0;
}