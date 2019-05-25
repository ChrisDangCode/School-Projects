/*--------------------------------------------------------------------
  A rational number calculator.
 
  Input:  rational numbers and operators
  Output: messages and results of operations on rational numbers

  Modified by Chris Dang		2/22/2015
 --------------------------------------------------------------------*/

#include <iostream>            // cin, cout, >>, <<
#include "RationalNumberHeader.h"           // Rational
using namespace std;


int main()
{
  const char HELP_INFO[] =
                  "\nA rational number x can be entered in the form"
                  "\na or a/b.  (e.g. 4, 3/4, 5/2)"
                  "\n"
                  "\nValid inputs:"
                  "\n x + y    addition (lowest terms)"
                  "\n x - y    subtraction (lowest terms)"
                  "\n x * y    multiplication (lowest terms)"
                  "\n x / y    division (lowest terms)"
                  "\n x I      inverse of x"
                  "\n x M      x as a mixed number"
                  "\n x R      x reduced to lowest terms"
                  "\n x G      greatest common divisor"
                  "\n x L y    lowest common denominator";

  const char BAD_INPUT[] = "*** Bad input! Type 'h' for help. ***\n";

  cout << "\nThis program is a rational number calculator.\n";

  for (;;)
  {
    cout << "\nInput (h=help,q=quit): ";

    if (cin.peek() == 'h')
    {
      cin.get();
      cout << HELP_INFO << endl;
    }

    else if (cin.peek() == 'q')
    {
      cin.get();
      return 0;
    }

    else
    {
      RationalNumber x, y;
      char op;

      cin >> x >> op;

      switch (op)
      {
        case '+':
                  cin >> y;
                  cout << x + y << endl;
                  break;

        case '-':
                  cin >> y;
                  cout << x - y << endl;
                  break;

        case '*':
                  cin >> y;
                  cout << x * y  << endl;
                  break;

        case '/':
                  cin >> y;
                  cout << x / y << endl;
                  break;

        case 'i': case 'I':
                  cout << x.invert() << endl;
                  break;


        case 'r': case 'R':
                  x.reduce();
                  cout << x << endl;
                  break;

        case 'g': case 'G':
                  cout << x.gcd() << endl;
                  break;

        case 'l': case 'L':
                  cin >> y;
                  cout << x.lcd(y) << endl;
                  break;

        default:
                  cout << BAD_INPUT;
      }
    }

    if (cin.fail())
    {
      cout << BAD_INPUT;
      cin.clear();
    }
    cin.ignore(9999,'\n');
  }
}
