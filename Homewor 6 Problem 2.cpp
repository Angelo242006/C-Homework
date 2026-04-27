#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

vector<char> userslettervector()
{
    char letter;
    vector<char> myVector;

    do
    {
        cout << "Insert a letter: " << endl;
        cin >> letter;
        if (isalpha(letter))   
        {
            myVector.push_back(letter);
        }         
    } while (isalpha(letter));

    return myVector;
}

void deleteRepeatedChars(vector<char>& myVector)    
{
    for (int letter = 0; letter < myVector.size(); letter++)
    {
        for (int someletter = letter + 1; someletter < myVector.size(); someletter++)
        {
            if (myVector[someletter] == myVector[letter]) 
            {
                myVector.erase(myVector.begin() + someletter);    
                someletter--;  
            }
        }
    }
}

void selectionSort(vector <char>& myVector)
{
    int maxIndex;

    for (int letter = 0; letter < myVector.size(); letter++)
    {
        maxIndex = letter;             

        for (int j = letter + 1; j < myVector.size(); j++)
        {
            if (myVector[j] > myVector[maxIndex])
            {
                maxIndex = j;
            }
        }
        swap(myVector[letter], myVector[maxIndex]);
    }
}

int main()
{
    vector<char> myVector = userslettervector();
    deleteRepeatedChars(myVector);
    selectionSort(myVector);

    for (int i = 0; i < myVector.size(); i++)
        cout << myVector[i] << " ";

    return 0;
}