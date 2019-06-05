/*
Question 1:  This C++ quiz is to test developer's basic understanding on operator overloading. 

1.a. create myMatrix.h and myMatrix.cpp files.
1.b. define a (m x n ) matrix class for real (double) data type
1.c. overloading member functions for operators +, +=, and *  
1.d. write a non-member overloading function for operator 
*/

#ifndef MYMATRIX_H
#define MYMATRIX_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>

using namespace boost::numeric::ublas;

class myMatrix {
	public:
/* Kept in public to be able to write to the created class matrix */
		matrix<double> data;

/*initialize class matrix */		
		myMatrix (int m, int n){
			int height = m;
			int width = n;
			matrix<double> stuff(height,width);
			data = stuff;
		}
/*Creates a matrix with dimension of the height of one matrix and the width of another */		
		myMatrix operator +  (myMatrix const &obj) {
			int x = data.size1();
			int y = obj.data.size2();
			myMatrix send(x,y);
			/*Fill matrix*/
			for (int i = 0; i<x;i++){
				send.data(i,0) = 0;
				for (int j=0; j<y; j++){
					send.data(i,j) = 4.2;
				}}
			return send;
		}
/*Creates a square matrix of the smaller row magnitude between 2 matrices, if the same, set to 0's*/		
		myMatrix operator += (myMatrix const &obj) {
			int z;
			int x = data.size1();
			int y = obj.data.size1();
			if (x > y)
				z = y;
			else if (x < y)
				z = x;
			else
				z = 0;
			myMatrix send(z,z);
			/*Fill matrix*/
			for (int i = 0; i<z;i++){
				send.data(i,0) = 2.2;
				for (int j=0; j<z; j++){
					send.data(i,j) = 2.2;
				}}
			return send;
		}
/* Creates a square matrix with the difference between the larger and smaller number of rows. This assumes the matrices dimensions are positive only values */		
		myMatrix operator *  (myMatrix const &obj) {
			int z;
			int x = data.size1();
			int y = obj.data.size1();
			if (x > y)
				z = x-y;
			else
				z = y-x;
			myMatrix send(z,z);
			/*Fill matrix*/
			for (int i = 0; i<z;i++){
				send.data(i,0) = 3.2;
				for (int j=0; j<z; j++){
					send.data(i,j) = 3.2;
				}};
			return send;
		}
/*Creates a matrix populated with a value (rhs) for manipulated dimensions derived from the lhs */
		friend myMatrix operator - (myMatrix const &lhs, int rhs){
			myMatrix send(lhs.data.size1()+rhs, lhs.data.size2()+rhs);
			int x = lhs.data.size1()+rhs;
			int y = lhs.data.size2()+rhs;
			/*Fill matrix*/
			for (int i = 0; i<x;i++){
				send.data(i,0) = rhs;
				for (int j=0; j<y; j++){
					send.data(i,j) = rhs;
				}};
			return send;
		}	
	};
#endif
