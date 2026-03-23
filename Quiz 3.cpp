#include <iostream>

using namespace std;

int findmaxscore (int scores[], int maxscores)
{
    int maxscore = scores[0];
    for (int i = 1; i < maxscores; i++)
    {
        if (scores[i] > maxscore)
        {
            maxscore = scores[i];
        }
    }
    return maxscore;
}

int findminscore (int scores[], int maxscores)
{
    int minscore = scores[0];
    for (int i = 1; i < maxscores; i++)
    {
        if (scores[i] < minscore)
        {
            minscore = scores[i];
        }
    }
    return minscore;
}

int averagescore (int scores[], int maxscores)
{
    int sum = 0;
    for (int i = 0; i < maxscores; i++)
    {
        sum += scores[i];
    }
    return sum / maxscores;
}

int stdevscore (int scores[], int maxscores)
{
    int sum = 0;
    for (int i = 0; i < maxscores; i++)
    {
        sum += scores[i];
    }
    int mean = sum / maxscores;
    int stdevsum = 0;
    for (int i = 0; i < maxscores; i++)
    {
        stdevsum += (scores[i] - mean) * (scores[i] - mean);
    }
    return sqrt(stdevsum / maxscores);
}

int main ()
{
    int score, maxscores;

    cout << "How many scores would you like to enter? ";
    cin >> maxscores;

    int scores [maxscores];

    for (int i = 0; i < maxscores; i++)
    {
        cout << "Enter a score between 0 and 100: ";
        cin >> score;
        while (score < 0 || score > 100)
        {
            cout << "Invalid score. Please enter a score between 0 and 100: ";
            cin >> score;
        }
        scores[i] = score;
    }

    int maxscore = findmaxscore(scores, maxscores);
    cout << "The highest score is: " << maxscore << endl;
    int minscore = findminscore(scores, maxscores);
    cout << "The lowest score is: " << minscore << endl;
    int x = averagescore(scores, maxscores);
    cout << "The average score is: " << x << endl;
    int y = stdevscore(scores, maxscores);
    cout << "The standard deviation is: " << y << endl;

    return 0;
}