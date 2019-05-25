/*---------------------------------------------------------------------
                  Driver program to test the Queue class.
				  Chris Dang			CSCI 1107
  ----------------------------------------------------------------------*/

#include <iostream>
using namespace std;
	
#include "LQueue.h"

void print(Queue q)
{ q.display(cout); }

int main()
{
   Queue q1;
   cout << "Queue created.  Empty? " << boolalpha << q1.empty() << endl;

   cout << "How many elements to add to the queue? \n9 elements\n";
   int numItems = 9;
  
   for (int i = 1; i <= numItems; i++) 
      q1.enqueue(111*i);

   cout << "Contents of queue q1:\n";
   q1.display(cout);
   cout << endl;
   cout << "\nFront of q1 is " << q1.front() << endl ;
  /* Queue q2;
   q2 = q1;
   cout << "Contents of queue q2 after q2 = q1:\n";
   q2.display(cout) ;
	cout <<  endl;

   cout << "Queue q2 empty? " << q2.empty() << endl;

   cout << "Front value in q2: " << q2.front() << endl;
   */
   while (!q1.empty())
   {
     cout << "Remove front -- Queue contents: ";
     q1.dequeue();
	 cout << endl ;
     q1.display(cout);
	 cout << endl;
   }
   cout << "Queue q1 empty? " << q1.empty() << endl;
   cout << "Front value in q1?" << endl << q1.front() << endl;
   cout << "Trying to remove front of q1: " << endl;
   q1.dequeue();
}
