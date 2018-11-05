// main.cpp
// Tests all functionality of the class My_matrix class.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "TemplatedMy_matrix.h"

void dataTypeF();
void dataTypeI();
void dataTypeLong();
// Some test cases are expected to throw an exception.
// Add more try and catch blocks as necessary for your code
// to finish execution.

// Test 1
// * Create an object of type My_matrix, called m1, using constructor
// * Initialize m1 in main (by assigning numbers to matrix elements)
// * Display m1 on the screen using the operator <<

// Test 2
// * Create an object of type My_matrix, called m2, using (default)
//   constructor
// * Open an input file containing a matrix (row by row)
// * Initialize m2 by reading from the input file using
//   the operator >>
// * Open an output file (can be empty)
// * Write m2 to the output file using the operator <<

//Test 3
// * Use the copy constructor to make a copy of m1 called m3
// * Apply the copy assignment to m1 called m4
// * Display m3 and m4 on the screen using the operator <<

// Test 4
// * Test the matrix multiplication operator (operator*)
// * Apply the multiplication operator to valid and invalid cases
// * Display the resulting matrix and its number of rows and columns

// Test 5
// * Test the matrix addition operator (operator+)
// * Apply the multiplication operator to valid and invalid cases
// * Display the resulting matrix and its number of rows and columns

int main() {
	
	int cont = 1;

	while (cont != 0)
	{
		cout << "                                            MENU              " << endl;
		cout << "                            1: Test class with float data type" << endl;
		cout << "                            2: Test class with integer data type" << endl;
		cout << "                            3: Test class with long integer type" << endl;


		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1: 
		{
			cout << "FLOAT TEST" << endl << endl;
			dataTypeF();
			break;
		}

		case 2: 
		{
			cout << "INTEGER TEST" << endl << endl;
			dataTypeI();
			break;
		}
		case 3: 
		{
			cout << "LONG INTEGER TEST" << endl << endl;
			dataTypeLong();
			break;
		}
		default:
			cout << "Not a choice." << endl;
		}
		cout << "Continue or try agian? (YES = 1, NO = 0)";
		cin >> cont;
	}
}



void dataTypeF()
{
	try {
		//--------------------------------------------------------------------------------------
		// Test 1 (Constructer & overloaded << operator)
		My_matrix <double> m1(3,4);
		double f = 2.4;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
				m1.elem(i, j) = f++;
		}
		cout << "Test 1:" << endl << "  M1 " << endl;
		cout << m1 << endl;
		//--------------------------------------------------------------------------------------

		// Test 2 (default contructer, >> operator, & << operator)
		cout << "Test 2:" << endl;
		My_matrix <double> m2;
		ifstream mat_file;
		try {
			mat_file.open("Matrix_float.txt");
			mat_file >> m2;
			mat_file.close();
		}
		catch (invalid_input & e)
		{
			cerr << e.what() << endl;
		}
		ofstream out_file;
		out_file.open("Output_float.txt");
		out_file << m2;
		out_file.close();
		cout << "Matrix file read...." << endl;
		cout << "Matrix object written to output file..." << endl << endl;


		//Test 3 (= operator)
		cout << "Test 3: " << endl;
		My_matrix<double> m4;
		My_matrix<double> m3 = m1;
		m4 = m1;
		cout << "  M3" << endl << m3 << endl;
		cout << "  M4" << endl << m4 << endl;
		//----------------------------------------------------------------------------------------------
		// Test 4(Matrix multiplication)
		cout << "Test 4:(Multiplication) " << endl << endl;
		cout << "****Test with VALID input****"  << endl << endl; // test valid input
		cout << "Matrix 1 " << endl;
		cout << m1 << endl << "  *  " << endl << endl;
		cout << "Matrix 2 " << endl;
		cout << m2 << endl << "   = " << endl << endl;
		My_matrix<double> m5(3, 4);
		try {
			m5 = m1 * m2;

			cout << endl << " Product: " << endl;
			cout << m5 << endl;
			cout << "Rows = " << m5.number_of_rows() << endl << endl;
			cout << "Columns = " << m5.number_of_columns() << endl << endl;
		}
		catch (incompatible_matrices &e) {
			cout << e.what() << endl << endl;
		}
		My_matrix<double> m6(3, 2);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
				m6.elem(i, j) = 2.3;
		}
		cout << "****Test with INVALID input****"  << endl << endl; // Test invalid input
		cout << "Matrix 1 " << endl;
		cout << m6 << endl << "   * " << endl << endl;
		cout << "Matrix 2 " << endl;
		cout << m1 << endl << "   = " << endl << endl;
		My_matrix<double> m7(3, 4);
		try {
			m7 = m6 * m1;

			cout << endl << "Product: " << endl;
			cout << m5 << endl;
			cout << "Rows = " << m5.number_of_rows() << endl << endl;
			cout << "Columns = " << m5.number_of_columns() << endl << endl;
		}
		catch (incompatible_matrices &e) {
				cout << e.what() << endl << endl;
			}
		//-----------------------------------------------------------------------------------------
		// Test 5
		cout << endl << "Test 5: (Addition) " << endl << endl;
		cout << "****Test with VALID input****"  << endl << endl; // test with valid input
		My_matrix<double> mSum(3, 4);
		cout << "Sum of Matrices: " << endl << endl;
		cout << "Matrix 1 " << endl;
		cout << m1 << endl << "   + " << endl << endl;
		cout << "Matrix 2 " << endl;
		cout << m3 << endl << "   = " << endl << endl;

		try {
			mSum = m1 + m3;

			cout << mSum << endl;
			cout << "Row = " << mSum.number_of_rows() << endl << endl;
			cout << "Columns = " << mSum.number_of_columns() << endl << endl;
		}
		catch (incompatible_matrices &e) {
			cout << e.what() << endl << endl;
		}

		cout << "****Test with INVALID input****" << endl << endl; // test with invalid input
		My_matrix<double> m8(2, 5);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 5; j++)
				m8(i, j) = 3.5;
		}
		cout << "Sum of Matrices: " << endl << endl;
		cout << "Matrix 1 " << endl;
		cout << m1 << endl << "   + " << endl << endl;
		cout << "Matrix 2 " << endl;
		cout << m8 << endl << "   = " << endl << endl;
		try {
			mSum = m1 + m8;

			cout << mSum << endl;
			cout << "Row = " << mSum.number_of_rows() << endl << endl;
			cout << "Columns = " << mSum.number_of_columns() << endl << endl;
		}
		catch (incompatible_matrices &e) {
			cout << e.what() << endl << endl;
		}


	}
	catch (invalid_input &error) {
		cerr << "Error: " << error.what() << endl;
	}
}

//-------------------------------------------------------------------------------

void dataTypeI()
{
	try {
		// Test 1 (Constructer & overloaded << operator)
		My_matrix <int> m1(3, 4);
		int f = 2;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
				m1.elem(i, j) = f++;
		}
		cout << "Test 1:" << endl << "   M1 " << endl;
		cout << m1 << endl;
		//--------------------------------------------------------------------------------------

		// Test 2 (default contructer, >> operator, & << operator)
		cout << "Test 2:" << endl;
		My_matrix <int> m2;
		ifstream mat_file;
		try {
			mat_file.open("Matrix_int.txt");
			mat_file >> m2;
			mat_file.close();
		}
		catch (invalid_input & e)
		{
			cerr << e.what() << endl;
		}
		ofstream out_file;
		out_file.open("Output_int.txt");
		out_file << m2;
		out_file.close();
		cout << "Matrix file read...." << endl;
		cout << "Matrix object written to output file..." << endl << endl;
	

		//Test 3 (Matrix multiplication)
		cout << "Test 3: " << endl;
		My_matrix<int> m4;
		My_matrix<int> m3 = m1;
		m4 = m1;
		cout << "  M3" << endl << m3 << endl;
		cout << "  M4" << endl << m4 << endl;
		//----------------------------------------------------------------------------------------------
		// Test 4
		cout << "Test 4:(Multiplication) " << endl << endl;
		cout << "****Test with VALID input****" << endl << endl; // test valid input
		cout << "Matrix 1 " << endl;
		cout << m1 << endl << "   * " << endl << endl;
		cout << "Matrix 2 " << endl;
		cout << m2 << endl << "   = " << endl << endl;
		My_matrix<int> m5(3, 4);
		try {
			m5 = m1 * m2;

			cout << endl << "Product: " << endl;
			cout << m5 << endl;
			cout << "Rows = " << m5.number_of_rows() << endl << endl;
			cout << "Columns = " << m5.number_of_columns() << endl << endl;
		}
		catch (incompatible_matrices &e) {
			cout << e.what() << endl << endl;
		}
		My_matrix<int> m6(3, 2);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
				m6.elem(i, j) = 2;
		}
		cout << "****Test with INVALID input****"  << endl << endl; // Test invalid input
		cout << "Matrix 1 " << endl;
		cout << m6 << endl << "   * " << endl << endl;
		cout << "Matrix 2 " << endl;
		cout << m1 << endl << "   = " << endl << endl;
		My_matrix<int> m7(3, 4);
		try {
			m7 = m6 * m1;

			cout << endl << "Product: " << endl;
			cout << m5 << endl;
			cout << "Rows = " << m5.number_of_rows() << endl << endl;
			cout << "Columns = " << m5.number_of_columns() << endl << endl;
		}
		catch (incompatible_matrices &e) {
			cout << e.what() << endl << endl;
		}
		//-----------------------------------------------------------------------------------------
		// Test 5
		cout << endl << "Test 5: (Addition) " << endl << endl;
		cout << "****Test with VALID input****"  << endl << endl; // test with valid input
		My_matrix<int> mSum(3, 4);
		cout << "Sum of Matrices: " << endl << endl;
		cout << "Matrix 1 " << endl;
		cout << m1 << endl << "   + " << endl << endl;
		cout << "Matrix 2 " << endl;
		cout << m3 << endl << "   = " << endl << endl;

		try {
			mSum = m1 + m3;

			cout << mSum << endl;
			cout << "Row = " << mSum.number_of_rows() << endl << endl;
			cout << "Columns = " << mSum.number_of_columns() << endl << endl;
		}
		catch (incompatible_matrices &e) {
			cout << e.what() << endl << endl;
		}

		cout << "****Test with INVALID input****"  << endl << endl; // test with invalid input
		My_matrix<int> m8(2, 5);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 5; j++)
				m8(i, j) = 3;
		}
		cout << "Sum of Matrices: " << endl << endl;
		cout << "Matrix 1 " << endl;
		cout << m1 << endl << "   + " << endl << endl;
		cout << "Matrix 2 " << endl;
		cout << m8 << endl << "   = " << endl << endl;
		try {
			mSum = m1 + m8;

			cout << mSum << endl;
			cout << "Row = " << mSum.number_of_rows() << endl << endl;
			cout << "Columns = " << mSum.number_of_columns() << endl << endl;
		}
		catch (incompatible_matrices &e) {
			cout << e.what() << endl << endl;
		}


	}
	catch (invalid_input &error) {
		cerr << "Error: " << error.what() << endl;
	}



}



void dataTypeLong()
{
	
	try {
		//--------------------------------------------------------------------------------------
		// Test 1 (Constructer & overloaded << operator)
		My_matrix <long> m1(3, 4);
		long f = 2;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
				m1.elem(i, j) = f++;
		}
		cout << "Test 1:" << endl << "   M1 " << endl;
		cout << m1 << endl;
		//--------------------------------------------------------------------------------------

		// Test 2 (default contructer, >> operator, & << operator)
		cout << "Test 2:" << endl;
		My_matrix <long> m2;
		ifstream mat_file;
		try {
			mat_file.open("Matrix_int.txt");
			mat_file >> m2;
			mat_file.close();
		}
		catch (invalid_input & e)
		{
			cerr << e.what() << endl;
		}
		ofstream out_file;
		out_file.open("Output_int.txt");
		out_file << m2;
		out_file.close();
		cout << "Matrix file read...." << endl;
		cout << "Matrix object written to output file..." << endl << endl;
	

		//Test 3 (Matrix multiplication)
		cout << "Test 3: " << endl;
		My_matrix<long> m4;
		My_matrix<long> m3 = m1;
		m4 = m1;
		cout << "  M3" << endl << m3 << endl;
		cout << "  M4:" << endl << m4 << endl;
		//----------------------------------------------------------------------------------------------
		// Test 4
		cout << "Test 4:(Multiplication) " << endl << endl;
		cout << "****Test with VALID input****"  << endl << endl; // test valid input
		cout << "Matrix 1 " << endl;
		cout << m1 << endl << "   * " << endl << endl;
		cout << "Matrix 2 " << endl;
		cout << m2 << endl << "   = " << endl << endl;
		My_matrix<long> m5(3, 4);
		try {
			m5 = m1 * m2;

			cout << endl << "Product: " << endl;
			cout << m5 << endl;
			cout << "Rows = " << m5.number_of_rows() << endl << endl;
			cout << "Columns = " << m5.number_of_columns() << endl << endl;
		}
		catch (incompatible_matrices &e) {
			cout << e.what() << endl << endl;
		}
		My_matrix<long> m6(3, 2);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
				m6.elem(i, j) = 2;
		}
		cout << "****Test with INVALID input****" << endl << endl; // Test invalid input
		cout << "Matrix 1 " << endl;
		cout << m6 << endl << "   * " << endl << endl;
		cout << "Matrix 2 " << endl;
		cout << m1 << endl << "   = " << endl << endl;
		My_matrix<long> m7(3, 4);
		try {
			m7 = m6 * m1;

			cout << endl << "Product: " << endl;
			cout << m5 << endl;
			cout << "Rows = " << m5.number_of_rows() << endl << endl;
			cout << "Columns = " << m5.number_of_columns() << endl << endl;
		}
		catch (incompatible_matrices &e) {
			cout << e.what() << endl << endl;
		}
		//-----------------------------------------------------------------------------------------
		// Test 5
		cout << endl << "Test 5: (Addition) " << endl << endl;
		cout << "****Test with VALID input****"  << endl << endl; // test with valid input
		My_matrix<long> mSum(3, 4);
		cout << "Sum of Matrices: " << endl << endl;
		cout << "Matrix 1 " << endl;
		cout << m1 << endl << "   + " << endl << endl;
		cout << "Matrix 2 " << endl;
		cout << m3 << endl << "   = " << endl << endl;

		try {
			mSum = m1 + m3;

			cout << mSum << endl;
			cout << "Row = " << mSum.number_of_rows() << endl << endl;
			cout << "Columns = " << mSum.number_of_columns() << endl << endl;
		}
		catch (incompatible_matrices &e) {
			cout << e.what() << endl << endl;
		}

		cout << "****Test with INVALID input****"  << endl << endl; // test with invalid input
		My_matrix<long> m8(2, 5);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 5; j++)
				m8(i, j) = 3;
		}
		cout << "Sum of Matrices: " << endl << endl;
		cout << "Matrix 1 " << endl;
		cout << m1 << endl << "   + " << endl << endl;
		cout << "Matrix 2 " << endl;
		cout << m8 << endl << "   = " << endl << endl;
		try {
			mSum = m1 + m8;

			cout << mSum << endl;
			cout << "Row = " << mSum.number_of_rows() << endl << endl;
			cout << "Columns = " << mSum.number_of_columns() << endl << endl;
		}
		catch (incompatible_matrices &e) {
			cout << e.what() << endl << endl;
		}


	}
	catch (invalid_input &error) {
		cerr << "Error: " << error.what() << endl;
	}

}





/*

// Function to test Matrix_muliplication input
void multiply(int n, int m, int r, int c)
{
	My_matrix<double> m5(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			m5.elem(i, j) = 3.43;
	}

	My_matrix<double> m6(r, c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			m6.elem(i, j) = 3.43;
	}
	My_matrix<double> m7(n, c);

	cout << "Matrix 1 " << endl;
	cout << m5 << endl << "   * " << endl << endl;
	cout << "Matrix 2 " << endl;
	cout << m6 << endl << "   = " << endl << endl;
	try {
		m7 = m5 * m6;
		
		cout << endl << "Product: " << endl;
		cout << m7 << endl;
		cout << "Rows = " << m7.number_of_rows() << endl << endl;
		cout << "Columns = " << m7.number_of_columns() << endl << endl;
	}
	catch (incompatible_matrices &e) {
		cout << e.what() << endl;
	}
	
}




//Function to test Matrix_addition input
void addition(int n, int m, int r, int c)
{
	My_matrix<double> m8(n,m);
	My_matrix<double> m9(r, c);
	My_matrix<double> m10(n, m);
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < m; j++)
			m8.elem(i, j) = 3.43;
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			m9.elem(i, j) = 3.34;
	}

	cout << "Sum of Matrices: " << endl << endl;
	cout << "Matrix 1 " << endl;
	cout << m8 << endl << "   + " << endl << endl;
	cout << "Matrix 2 " << endl;
	cout << m9 << endl << "   = " << endl << endl;

	try {
		m10 = m8 + m9;
		
		cout << m10 << endl;
		cout << "Row = " << n << endl << endl;
		cout << "Columns = " << m << endl << endl;
	}
	catch (incompatible_matrices &e) {
		cout << e.what() << endl;
	}
	
	
}
*/