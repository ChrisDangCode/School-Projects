//******************************************************************************
//  Programmer: Chris Dang			Class: CSCI 1107 Spring 2015
// 
//  Description: User is asked to enter the side length of a square. When the 
//	input is verified, a magic square is created and then displayed, as well 
//	as verified by an internal function.
//******************************************************************************

#include <iostream>
#include <iomanip>
using namespace std ;

int getMagicSum(int length) ;
int isMagicRows(int length, int magicSum, int **&sqrPtr) ;
int isMagicCols(int length, int magicSum, int **&sqrPtr) ;
int isMagicStairDownRight(int length, int magicSum, int **&sqrPtr) ;
int isMagicStairUpRight(int length, int magicSum, int **&sqrPtr)	;
bool isMagicSquare(int length, int magicSum, int **&sqrPtr) ;
void constructSquare(int length, int **&sqrPtr) ;


int main() {

	int **sqrPtr ;
	int length ;

	cout << "Enter the length of the sides of a square (number must be odd): " ;
	cin >> length ;
	while (length % 2 == 0){ // if sides are even ints, user is trapped until odd int is entered
		cout << "Enter the length of the sides of a square (number must be odd): " ;
		cin >> length ;
	} // end while
	
	int magicSum = getMagicSum(length) ;

	constructSquare(length, sqrPtr) ;

	isMagicSquare(length, magicSum, sqrPtr) ;

return 0 ;
	}// end main



void displayTable(int rows, int cols, int **&sqrPtr) {


	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++)
			cout << setw(3) << sqrPtr[i][j] ;
		cout << endl ;
	}// end for
		cout << endl ;

} // end displayTable

int getMagicSum(int length){

	//magic square formula = n(n^2 + 1) / 2
	int sum = ((length * ((length * length) + 1)) / 2) ;

	return sum ;

}// end magicSum

int isMagicRows(int length, int magicSum, int **&sqrPtr) {


	for(int i = 0; i < length; i++) {
		int sum = 0 ;
		for (int j = 0; j < length; j++)
			sum = sum + sqrPtr[i][j] ;
			if (sum != magicSum) 
				return false ; 
	}// end for

	return magicSum ;

}// end isMagicRows

int isMagicCols(int length, int magicSum, int **&sqrPtr) {


	for(int i = 0; i < length; i++) {
		int sum = 0 ;
		for (int j = 0; j < length; j++)
			sum = sum + sqrPtr[j][i] ;
			if (sum != magicSum) 
				return false ; 
	}// end for

	return magicSum ;

}// end isMagicCols

int isMagicStairDownRight(int length, int magicSum, int **&sqrPtr) {


	for(int i = 0; i < length;) {
		int sum = 0 ;
		for (int j = 0; j < length; j++, i++)
			sum = sum + sqrPtr[j][i] ;
			if (sum != magicSum) 
			return false ; 
	}// end for

	return magicSum ;

}// end isMagicStairDownRight

int isMagicStairUpRight(int length, int magicSum, int **&sqrPtr) {

	for(int i = 0; i < length;) {
		int sum = 0 ;
		for (int j = (length - 1); j >= 0; j--, i++)
			sum = sum + sqrPtr[j][i] ;
			if (sum != magicSum) 
				return false ; 
	}// end for

	return magicSum ;

}// end isMagicStairUpRight

bool isMagicSquare(int length, int magicSum, int **&sqrPtr) {

	if (isMagicRows(length, magicSum, sqrPtr) == magicSum && isMagicCols(length, magicSum, sqrPtr)  == magicSum && isMagicStairDownRight(length, magicSum, sqrPtr) == magicSum && isMagicStairUpRight(length, magicSum, sqrPtr) == magicSum){
		cout << "That is a magic square.\n\n" ;
		return true ;
	}// end if
	else {
		cout << "That is not a magic square\n\n" ;
		return false; 
	}//end else

}// end isMagicSquare

void constructSquare(int length, int **&sqrPtr) {

		int count = 1 , row = 0, col = (length/2) ;

		sqrPtr = new int *[length] ;

		for (int i = 0; i < length; i++)
			sqrPtr[i] = new int[length] ;

				//Load array with 0's
		for(int k=0;k < length;k++){
			for(int c=0; c < length; c++)
				sqrPtr[k][c] = 0 ;
		}// end for
		

		/*
		//top center of array is always set to 1
		sqrPtr[0][(length/2)+1] = 1 ;
		for(int i = 2; i <= (length*length); i++) {
			*/
		/*
		int count = 2 ;

		int i = 2 ;
		int j = 2 ;
		sqrPtr[0][(length/2)+1] = 1 ;

		while (count <= (length*length))  {
			if (sqrPtr[++i%length][++j%length] == NULL)
				sqrPtr[i%length][j%length] = count ;
			else //(sqrPtr[i][(--j)%length]  == NULL)
				sqrPtr[i&length][--j%length] = count ;
			i = (++i % length) ;
			j = (++j % length) ;
			count++ ;
		}// end while

		for(int k=0;k<length;k++){
			for(int c=0; c<length; c++){
				cout << setw(4) << sqrPtr[k][c] ;
			}
			cout << endl;
		}
		*/

		sqrPtr[row][col] = count++ ;

		while (count <= length*length) {

		//	if (row < 0)
		//		row =  ;
		//	else 
		//		--row ;
		//	if (col == length - 1)
		//		col = 0 ;
		//	else 
		//		col = (col + 1) % length ;
		//	if (sqrPtr[row][col] == 0)
		//		sqrPtr[row][col] = count ;
		//	else {
		//		row -= 1 ;
		//		if (col == 0)
		//			col = length - 1 ;
		//		else if (col == 1)
		//			col = length - 2 ;
		//		else
		//			col -= 2 ;
		//		sqrPtr[row][col] = count ;
		//	}// end else
		//	if (row == length - 1 && col == length - 1) {
		//		row += 1 ;
		//		if (row == length)
		//			row = 0 ;
		//		sqrPtr[row][col] = count ;
		//	}// end if
		//	count++ ;
		//}// end while


			if (sqrPtr[row][col] == sqrPtr[0][length - 1]){
				++row  ;
				sqrPtr[row][col] = count++ ;
			}// end if

			// move up a row
			--row ;
			if (row < 0) // jump to bottom row if past top row
				row = length - 1 ;
			//move right a col
			++col ;
			if (col > length - 1) // jump to left most col
				col = 0 ;
			if (sqrPtr[row][col] == 0)
				sqrPtr[row][col] = count++ ;
			else { //if spot is not empty, return to orignal spot
				row += 2 ; // and down one row
				if (row > length - 1)
					row = length - 1 ;
				--col  ;
				if (col < 0) 
					col = 0 ;
				sqrPtr[row][col] = count++ ;
			} // end else

		} // end while

			for(int k=0;k<length;k++){
			for(int c=0; c<length; c++){
				cout << setw(3) << sqrPtr[k][c] ;
			}
			cout << endl << endl ;
		}


}// end constructSquare
