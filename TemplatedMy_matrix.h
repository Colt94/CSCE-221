/* TemplatedMy_matrix.h

Header file for the class TemplatedMy_matrix

Colton Monts    UIN: 326007133

*/

#include <iostream>
#include <stdexcept>

using namespace std;
// Definitions of user defined type exceptions 

struct invalid_input : public exception {
  virtual const char* what() const throw()
  { return "Invalid matrix input"; }
};

struct incompatible_matrices : public exception {
  virtual const char* what() const throw()
  { return "Incompatible matrices"; }
};


template <class T> class My_matrix {
	
  //member variables
  int n, m;
  T **ptr;
  void allocate_memory();  // optional
  
public:	
  //member functions
  My_matrix();  // default constructor
  My_matrix(int n1, int m1); // parameter constructor
  ~My_matrix(); // destructor
  My_matrix(const My_matrix<T>& mat); // copy constructor
  //My_matrix(My_matrix&& mat);  // move constructor (optional)
  My_matrix<T>& operator=(const My_matrix<T>& mat); //copy assignment operator
  //My_matrix& operator=(My_matrix&& mat); // move assignment operator (optional)
  int number_of_rows() const; 
  int number_of_columns() const;
  T* operator()(int i) const; // overloaded to access to ith row
  T& operator()(int i, int j); // overloaded to access (i,j) element
  T operator()(int i, int j) const; // overloaded to access (i,j) element
  T elem(int i, int j) const; // overloaded to access (i,j) element
  T& elem(int i, int j); // overloaded to access (i,j) element
};

// see the handout for the description of these operators
template <class T>
ostream& operator<<(ostream& out, const My_matrix<T>& mat);
template <class T>
istream& operator>>(istream& in, My_matrix<T>& mat);
template <class T>
My_matrix<T> operator+(const My_matrix<T>& mat1, const My_matrix<T>& mat2);
template <class T>
My_matrix<T> operator*(const My_matrix<T>& mat1, const My_matrix<T>& mat2);




template <class T>
My_matrix<T>::My_matrix()
	:n(0), m(0)
{
	ptr = new T*[n];
	for (int i = 0; i<n; i++)
	{
		ptr[i] = new T[m];
	}
}

template <class T>

void My_matrix<T>::allocate_memory()
{
}

template <class T>
My_matrix<T>::My_matrix(int n1, int m1)
{
  n = n1;
  m = m1;
  if (n < 0 || m < 0)
	  throw invalid_input();
  ptr = new T* [n];
  for(int i = 0;i<n;i++)
  {
  	ptr[i] = new T[m];
  }
}

template <class T>
My_matrix<T>::My_matrix(const My_matrix& mat)
{
	n = mat.n;
	m = mat.m;
	ptr = new T*[n];
	for (int i = 0; i<n; i++)
	{
		ptr[i] = new T[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ptr[i][j] = mat.ptr[i][j];
			
		}

	}
	
}

// move constructor (optional)
//My_matrix::My_matrix(My_matrix&& mat)
//{
  // add your code here
//}

template <class T>
My_matrix<T>::~My_matrix()
{
	for (int i = 0;i<n;i++)
	{
		delete[] ptr[i];
	}
	delete[] ptr;
}

template <class T>
My_matrix<T>& My_matrix<T>::operator=(const My_matrix<T>& mat)
{
	if (this != &mat)
	{
		
		if (n != mat.n || m != mat.m)
		{
			n = mat.n;
			m = mat.m;
			delete[] ptr;
			ptr = new T*[n];
			for (int i = 0; i<n; i++)
			{
				ptr[i] = new T[m];
			}

		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				ptr[i][j] = mat.ptr[i][j];
			}
		}
	}
	return *this;
}
// move assignment operator (optional)
//My_matrix& My_matrix::operator=(My_matrix&& mat)
//{
  // add your code here
//}

template <class T>
int My_matrix<T>::number_of_rows() const
{
	return n; 
  // add your code here
}

template <class T>
int My_matrix<T>::number_of_columns() const
{
	return m;
}

template <class T>
T* My_matrix<T>::operator()(int i) const
{
	T *row = ptr[i];
	return row;
}

template <class T>
T My_matrix<T>::operator()(int i, int j) const
{
	return ptr[i][j];
}

template <class T>
T& My_matrix<T>::operator()(int i, int j)
{
	return ptr[i][j];
}


template <class T>
T My_matrix<T>::elem(int i, int j) const
{
 
  if (i < 0 || i >= n) throw out_of_range("Out of range");
  if (j < 0 || j >= m) throw out_of_range("Out of range");
  return ptr[i][j];
  // add your code here
}

template <class T>
T& My_matrix<T>::elem(int i, int j)
{
	return ptr[i][j];

}

template <class T>
ostream& operator<<(ostream& out, const My_matrix<T>& mat)
{
	int r = mat.number_of_rows();
	int c = mat.number_of_columns();
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c;j++)
		{
			out << mat.elem(i,j) << "  ";
		}
	
		out << "\n";
	}
	return out;
  
  
}

template <class T>
istream& operator>>(istream& in, My_matrix<T>& mat)
{
	int r = 0;
	int c = 0;
	int count = 0;
	in >> r >> c;
	int size = (r*c);
	My_matrix<T> temp(r, c);
	mat = temp;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			in >> mat(i, j);
			count++;
		}
		cout << endl;
	}
	if (count != size)
		throw invalid_input();
	return in;
}




template <class T>
My_matrix<T> operator+(const My_matrix<T>& mat1, const My_matrix<T>& mat2)
{
	int r = mat1.number_of_rows();
	int c = mat1.number_of_columns();
	int r1 = mat2.number_of_rows();
	int c1= mat2.number_of_columns();
	if (r != r1 || c != c1)
	{
		throw incompatible_matrices();
	}
	My_matrix<T> temp(r,c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			temp.elem(i,j) = mat1.elem(i, j) + mat2.elem(i, j);
		}
	}
	return temp;
}

template <class T>
My_matrix<T> operator*(const My_matrix<T>& mat1, const My_matrix<T>& mat2)
{
	T sum = 0;
	My_matrix<T> temp(mat1.number_of_rows(), mat2.number_of_columns());
	if (mat1.number_of_columns() != mat2.number_of_rows())

	{
		throw incompatible_matrices();
	}
	for (int i = 0; i < mat1.number_of_rows(); i++)
	{
		for (int j = 0; j < mat2.number_of_columns(); j++)
		{
			for (int k = 0; k < mat1.number_of_columns(); k++)
			{
				sum += (mat1.elem(i, k)*mat2.elem(k, j));
			}

			temp.elem(i, j) = sum;
			sum = 0;
		}
		
	}
	return temp;

}
