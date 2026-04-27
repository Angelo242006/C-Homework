#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getnumbers()
{
    int number;
    vector<int> numbers;

    do
    {
        cout << "Insert a number (Stop inserting with a negative number): ";
        cin >> number;
        if (number >= 0)     
            numbers.push_back(number);
    } while (number > 0);

    return numbers;
}

void histogramcalculation(const vector<int>& numbers)
{
    int largest = *max_element(numbers.begin(), numbers.end());
    int maxbins = (largest / 10) + 1;

    vector<int> bins(maxbins, 0);

    for (int i = 0; i < (int)numbers.size(); i++)
    {
        int binIndex = numbers[i] / 10;
        bins[binIndex]++;
    }

    for (int i = 0; i < (int)bins.size(); i++)
    {
        cout << "bin " << i * 10 << " - " << (i * 10) + 9 << ": " << bins[i] << endl;
    }
}

int main()
{
    vector<int> numbers = getnumbers();
    histogramcalculation(numbers);

    return 0;
}