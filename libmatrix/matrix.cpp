/**
 *    Description:  A matrix
 *        Version:  1.0
 *        Created:  27/10/2015 12:16:26
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Kyle Robbertze (kr), paddatrapper@gmail.com
 */

#include "matrix.h"
namespace libmatrix
{
Matrix::Matrix(Matrix::matrix_t matrix): matrix(matrix)
{
}

Matrix::matrix_t Matrix::getMatrix() const
{
	return this->matrix;
}

int Matrix::getNumRows() const
{
	return this->matrix.size();
}

int Matrix::getNumColumns() const
{
	return this->matrix.at(0).size();
}

double Matrix::get(int row, int column) const
{
	return this->matrix.at(row).at(column);
}

Matrix operator+(const Matrix &a, const Matrix &b)
{
	Matrix::matrix_t vector = a.getMatrix();
	for(int i = 0; i < a.getNumRows(); i++)
		for (int j = 0; j < a.getNumColumns(); j++) {
			double value = a.get(i, j) + b.get(i, j);
			auto &row = vector.at(i);
			row.at(j) = value;
		}
	return Matrix(vector);
}

std::ostream& operator<<(std::ostream &os, const Matrix &obj)
{
	os << "\u14A5";
	for (int i = 0; i < obj.getNumColumns(); i++)
		os << " ";
	os << "\u14A3\n";
	for (auto &row : obj.matrix) {
		os << "|";
		for (auto &digit : row)
			os << digit;
		os << "|\n";
	}
	os << "\u14AA";
	for (int i = 0; i < obj.getNumColumns(); i++)
		os << " ";
	os << "\u14A7\n";
	return os;
}
}
