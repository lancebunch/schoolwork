#include <iostream>
using namespace std;
#include <vector>

void promptNumbers(vector <int> &myVector)
{
   int number;
   do
   {
      cout << "Enter a number (stop with '0'): ";
      cin >> number;
      if (number != 0)
      {
         myVector.push_back(number);
      }
   }
   while (number != 0);
}

void displayNumbers(vector <int> &myVector)
{
   //displays through the vector through loop means
   for (int i = 0; i < myVector.size(); i++)
   {
      cout << "My Numbers[" << i << "] =" << myVector[i] << endl;
   }

   //displays numbers through an iterator
   vector<int>::iterator myIter = myVector.begin();
   while (myIter != myVector.end());
   {
      cout < *myIter << endl;
      myIter++;
   }
}

void removeOdds(vector <int> &myVector)
{

}

int main()
{
   vector <int> myVector;

   promptNumbers(myVector);
   displayNumbers(myVector);
   removeOdds(myVector);
   displayNumbers(myVector);
}