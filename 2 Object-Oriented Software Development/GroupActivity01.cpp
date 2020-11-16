#include <iostream>
using namespace std;
struct Scripture
{
    string bookName;
    int chapter;
    int verse;
};

struct Insight
{
    Scripture scrip;
    string thoughts;
};

void promptScripture(Insight spiritual[])
{
	for (int i = 0; i < 3; i++)
   {
	cout << "What is the #" << i + 1 << " scripture?\n";
      cout << "Book: ";
      getline(cin, spiritual[i].scrip.bookName);
      cout << "Chapter: ";
      cin >> spiritual[i].scrip.chapter;
      cout << "Verse: ";
      cin >> spiritual[i].scrip.verse;
		cin.ignore();
	}
}

void displayScripture(const Insight spiritual[])
{
	for (int i = 0; i < 3; i++)
	{
   	cout << spiritual[i].scrip.bookName << " "
      	  << spiritual[i].scrip.chapter << ":"
           << spiritual[i].scrip.verse << endl;
	}
}

void userThoughts(Insight spiritual[])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Any thoughts for " 
			  << spiritual[i].scrip.bookName << " "
      	  << spiritual[i].scrip.chapter << ":"
           << spiritual[i].scrip.verse << "?\n";
		getline(cin, spiritual[i].thoughts); 
	}
}

void displayThoughts(const Insight spiritual[])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Here are your thoughts for "
			  << spiritual[i].scrip.bookName << " "
      	  << spiritual[i].scrip.chapter << ":"
           << spiritual[i].scrip.verse << endl
			  << spiritual[i].thoughts << endl;
	}
}

int main()
{
    Insight spiritual[3]; 
    
    promptScripture(spiritual);

    displayScripture(spiritual);

	 userThoughts(spiritual);

	 displayThoughts(spiritual);
}