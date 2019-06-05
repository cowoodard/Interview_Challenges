/*
Question 1:  This C++ quiz is to test developer's basic understanding on operator overloading. 

1.a. create myMatrix.h and myMatrix.cpp files.
1.b. define a (m x n ) matrix class for real (double) data type
1.c. overloading member functions for operators +, +=, and *  
1.d. write a non-member overloading function for operator 
*
* 
* 
* Below is the very simple and trivial int main(), with minimal error checking to test base functionality from myMatrix.h and satisfy the focus of question #1
*/


#include "myMatrix.h"

int main(){
	/*check matrix class creation and ability to write double values*/
	myMatrix newmatrix(2,3), oldmatrix(4,5);	
	newmatrix.data(0,0) = 9.123+5.678;
	std::cout<<newmatrix.data<<std::endl;
	std::cout << " " << std::endl;
	
	/*check overload + */
	myMatrix newNewmatrix = newmatrix + oldmatrix;
	std::cout<<newNewmatrix.data<<std::endl;
	std::cout << " " << std::endl;
	
	/*check overload += */
	myMatrix TESTmatrix = newmatrix += oldmatrix;
	std::cout<<TESTmatrix.data<<std::endl;
	std::cout << " " << std::endl;
	
	/*check overload * */
	myMatrix anotherMatrix = newmatrix * oldmatrix;
	std::cout<<anotherMatrix.data<<std::endl;
	std::cout << " " << std::endl;
	
	/*check non-member overload - */
	myMatrix woahMatrix = newmatrix - 2;
	std::cout<<woahMatrix.data<<std::endl;
	std::cout << " " << std::endl;
	
	/*double check data pull from matrix*/
	double a = woahMatrix.data(0,0)+newNewmatrix.data(0,0);
	std::cout<<a<<std::endl;
	
	return 0;
}



