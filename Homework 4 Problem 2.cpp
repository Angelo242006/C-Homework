#include <iostream>
using namespace std;

int main()
{

    // Input the degree of difficulty
    double difficulty;

    cout << "What is the degree of difficulty (This ranges from 1.2 to 3.8 points)?" << endl;
    cin >> difficulty;
    cout << endl;

    while ((difficulty < 1.2) || (difficulty > 3.8))
    {
        cout << "This difficulty level is invalid, insert a level in between 1.2 and 3.8." << endl;
        cin >> difficulty;
    }

    double scores[7], score;

    for (int i = 0; i < 7; i++)
    {
        cout << "What is the score from the judge?" << endl;
        cin >> score;
        cout << endl;

        while ((score < 0) || (score > 10))
        {
            cout << "This score is invalid, insert a score in between 0 and 10." << endl;
            cin >> score;
        }
        scores[i] = score;
    }

    // Locating my maximum score
    double maxscore = scores[0];
    for (int i = 0; i < 7; i++)
    {
        if (scores[i] > maxscore)
        {
            maxscore = scores[i];
        }
    }

    // Locating my minimum score
    double minscore = scores[0];
    for (int i = 0; i < 7; i++)
    {
        if (scores[i] < minscore)
        {
            minscore = scores[i];
        }
    }

    // Summing the scores besides maximum and minimum values
    double sum = 0;
    for (int i = 0; i < 7; i++)
    {
        sum += scores[i];
    }
    sum = (sum - maxscore - minscore);
    sum = (sum * difficulty * 0.6);

    cout << "The final score is " << sum << endl;

    return 0;
}