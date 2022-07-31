
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using std::cout;
using std::endl;
using std::cerr;
using std::string;




template<class T>
class Matrix
{
public:
	Matrix(std::vector<std::vector<T>> m = {})
	{
		this->mat = m;
	}


	std::vector<std::vector<T>> mat;
};




template<typename T>
Matrix<T> matmul(Matrix<T> a, Matrix<T> b)
{
	//cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAH" << endl;
	int colsA = a.mat[0].size();
	int rowsA = a.mat.size();

	int colsB = b.mat[0].size();
	int rowsB = b.mat.size();
 	//cout << colsA << "x" << rowsA << " || " << rowsB << "x" << colsB << endl;


	if (colsA != rowsB)
	{
		cout << "Columns of A must match Rows of B" << endl;
		return Matrix<T>();
	}

	Matrix<T> result;
	result.mat.resize(rowsA);
	for (int i = 0; i < rowsA; ++i)
	{
		result.mat[i].resize(colsB);
	}

	for (int i = 0; i < rowsA; i++)
	{
		for (int j = 0; j < colsB; j++)
		{
			T sum = 0.0;
			for (int k = 0; k < colsA; k++)
			{
				sum += a.mat[i][k] * b.mat[k][j];
			}
			result.mat[i][j] = sum;
		}
	}

	return result;
}



template<typename T>
void showMatrix(Matrix<T> a)
{

	for (int i = 0; i < a.mat.size(); ++i)
	{
		for (int j = 0; j < a.mat[0].size(); ++j)
		{
			cout << a.mat[i][j] << " ";
		}
		cout << endl;
	}
}

/*
Matrix<int> FLOATtoINTmatrix(Matrix<float> a)
{
	Matrix<int> result;
	result.mat.resize(a.mat.size());
	for (int i = 0; i < a.mat.size(); ++i)
	{
		result.mat[i].resize(a.mat[0].size());
	}


	for (int i = 0; i < a.mat.size(); ++i)
	{
		for (int j = 0; j < a.mat[0].size(); ++j)
		{
			result.mat[i][j] = (int)a.mat[i][j];
		}
	}

	return result;



}


std::vector<float> INTtoFLOATpoint(std::vector<int> p)
{
	std::vector<float> res;
	res.resize(p.size());
	for (int i = 0; i < p.size(); ++i)
	{
		res[i] = (float)p[i];
	}
	return res;
}
*/


#endif /*MATRIX_H*/