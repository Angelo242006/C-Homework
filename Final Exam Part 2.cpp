#include <iostream>
#include <string>

using namespace std;

class Book
{
    public:
        string title;
        string author;
        string isbn;

        Book(string t, string a, string i) : title(t), author(a), isbn(i) {}
};

void selectionSort(vector<char>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

void numericalChoice1 (string& title, string& author, string& isbn, vector<Book>& library, int& numericalChoice)
{
    cout << "What book would you like to add to the database?" << endl;
    cin >> title;
    cout << endl;

    cout << "Who is the author of the book?" << endl;
    cin >> author;
    cout << endl;

    cout << "What is the ISBN of the book?" << endl;
    cin >> isbn;
    cout << endl;

    library.push_back(Book(title, author, isbn));


}

void numericalChoice2 (string& title, vector<Book>& library, int& numericalChoice)
{
    cout << "What book would you like to delete from the database?" << endl;
    cin >> title;
    cout << endl;

    for (int i = 0; i < library.size(); i++)
    {
        if (library[i].title == title)
        {
            library.erase(library.begin() + i);
            cout << "Book deleted." << endl;
            break;
        }
    }
    cout << "\n";
}

void numericalChoice3 (vector<Book>& library, int& numericalChoice)
{
    vector <char> authorVector;

    for (int i = 0; i < library.size(); i++)
    {
        authorVector.push_back(library[i].author[0]);
    }

    selectionSort(authorVector);

    for (int i = 0; i < authorVector.size(); i++)
    {
        cout << authorVector[i] << endl;
    }
    cout << "\n";
}

void theprompt (int& numericalChoice)
{
    cout << "Select from the following choices: " << endl;
    cout << "1. Add a new book" << endl;
    cout << "2. Delete a book" << endl;
    cout << "3. Print listing sorted by author" << endl;
    cout << "4. Exit" << endl;
    cin >> numericalChoice;
}

int main ()
{
    int numericalChoice;
    string title, author, isbn;
    vector <Book> library;

    theprompt(numericalChoice);

    if (numericalChoice == 1)
    {        
        numericalChoice1(title, author, isbn, library, numericalChoice);
            theprompt(numericalChoice);
    }

    else if (numericalChoice == 2)
    {
        numericalChoice2(title, library, numericalChoice);
            theprompt(numericalChoice);
    }

    else if (numericalChoice == 3)
    {
        numericalChoice3(library, numericalChoice);
            theprompt(numericalChoice);
    }

    else if (numericalChoice == 4)
    {
        cout << "Have a great day!" << endl;
        return 0;
    }

    return 0;
}