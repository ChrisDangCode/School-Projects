#include <iostream>
#include "circq.h"
using namespace std;

class Student {
private:
	int studentId ;
	string name ;

public:

/*****************************************************************************
Default Constructor creates a student object

Pre: None

Post: A student profile is created with placeholder student ID and name
******************************************************************************/
	Student(){studentId = 000; name = "Jamie Doe";}

/*****************************************************************************
read

Pre: Pass in istream object

Post: Records number and name for student
******************************************************************************/
	void read (istream &in) {

			in >> studentId ; // record student ID

			in >> name ;	 // record student name

	} // end read

/****************************************************************************
  display

  pre: must pass ostream operator

  post: displays student ID and name of student
****************************************************************************/
	void display(ostream &out) const{ 
		out << "Student ID: " << studentId << "   Name: " << name ;
	} // end display 

} ; // end student class

// non-member function for student

/*****************************************************************************
operator<<: Overloaded operator which allows you to display the contents
			of the entire Queue

Pre: ostream must be opened and the const parameter is passed by reference
  
Post: Calls the method display that displays the entire Queue.
	  
******************************************************************************/
ostream &operator<<(ostream& out, const Student &student) {
	student.display(out) ;
	return out;
} // end overloaded << op

/*****************************************************************************
operator>>: Overloaded operator which allows you to insert records

Pre: istream must be opened and the student record passed by value
  
Post: inserts student into record
	  
******************************************************************************/
istream &operator>>(istream& in, Student &student) {
	student.read(in) ;
	return in ;
} // end overloaded << op	

/*****************************************************************************
operator<<: Overloaded operator which allows you to display the contents
			of the entire student Queue

Pre: ostream must be opened and the const parameter is passed by reference.
Must be used with student queue.
  
Post: Calls the method display that displays the entire Queue.
	  
******************************************************************************/
template <typename qElement>
void displayStudent(ostream &out, CircularQ<qElement> student) {
	
	while (!student.empty()) {
		out << *(student.front()) << endl ;
		student.dequeue() ;
	}// end while
}// end displayStudent
		


int main(){

		CircularQ <double> qdub1 ;			// holds 0.0, 1.1, 2.2 ... 9.9
		CircularQ <double> qdub2 ;			// holds user inputted doubles
		CircularQ <double> qdub ;			// tests assignment operator
		CircularQ <string> qstring ;		// holds strings
		CircularQ <Student> qstu ;			// holds students names
		CircularQ <Student*> stuPtrQ ;		// holds anonimous variables
		CircularQ <CircularQ<double>> qq ;  // holds qdub1, qdub2, qdub
		
		
		for (int i = 0; i <= 9 ; i++) // loads queue with 0, 1.1, 2.2 ... 9.9
			qdub1.enqueue(i * 1.1) ;
		
		cout << "Please enter 5 double values: " ;	// loads queue with 5 user values
		for (int i = 0; i < 5 ; i++) {
			double temp ;
			cin >> temp ;
			qdub2.enqueue(temp) ;
		} // end for

		cout << "qdub1 contains: " << qdub1 << endl ;
		cout << "qdub2 contains: " << qdub2 << endl << endl ;

		qdub = join(qdub1, qdub2) ;			// testing assignment operator
		cout << "qdub contains: " << qdub << endl ;

		cout << "\nCreating student account.\n " ; // testing student class
		Student s ;

		cout << "Enter ID for student and name for student: " ; // testing student class
		cin  >> s ; 
		cout << s << endl ;

		// tests Queue holding student records
		cout << "Enter number of students: " ;	// get number of students from user
		int num ;
		cin >> num ;

		for (int i = 0; i < num; i++) {   // get student records from user
			Student temp ;
			cout << "Enter ID for student and name for student: " ;
			cin >> temp ;
			qstu.enqueue(temp) ;
		} // end for

		cout << "Students are: " << qstu ;	// display records
		cout << endl << endl ;

		// tests Queue holding student records that are anonymous
		cout << "Enter number of students: " ;  // get number of students from user
		int num2 ;
		cin >> num2 ;

		for (int i = 0; i < num2; i++) {   // get student records from user
			Student temp ;
			cout << "Enter ID for student and name for student: " ;
			cin >> temp ;
			Student *anon ;
			anon = new Student ;
			*anon = temp ;
			stuPtrQ.enqueue(anon) ;
		} // end for

		// displaying student info with memory addresses
		cout << "Memory locations of students are: " << stuPtrQ << endl ;
		cout << "Students are:\n" ;
		displayStudent(cout, stuPtrQ) ;
		cout << endl << endl ;

		// loading qq with queues
		qq.enqueue(qdub1) ;
		qq.enqueue(qdub2) ;
		qq.enqueue(qdub) ;

		cout << "qq contains: " << qq ;		/// output queue
		
	return 0;
}// end main

