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

Matrix operator-(const Matrix &a, const Matrix &b)
{
	Matrix::matrix_t vector = a.getMatrix();
	for(int i = 0; i < a.getNumRows(); i++)
		for (int j = 0; j < a.getNumColumns(); j++) {
			double value = a.get(i, j) - b.get(i, j);
			auto &row = vector.at(i);
			row.at(j) = value;
		}
	return Matrix(vector);
}

Matrix operator*(const int &n, const Matrix &a)
{
	Matrix::matrix_t vector = a.getMatrix();
	for(int i = 0; i < a.getNumRows(); i++)
		for (int j = 0; j < a.getNumColumns(); j++) {
			double value = a.get(i, j) * n;
			auto &row = vector.at(i);
			row.at(j) = value;
		}
	return Matrix(vector);
}

std::ostream& operator<<(std::ostream &os, const Matrix &obj)
{
	os << "\u23a1";
	for (auto &digit : obj.matrix.at(0))
		os << digit << "\t";
	os << "\u23a4\n";
	for (int i = 1; i < obj.matrix.size() - 1; i++) {
		auto &row = obj.matrix.at(i);
		os << "\u23a2";
		for (auto &digit : row)
			os << digit << "\t";
		os << "\u23a5\n";
	}

	os << "\u23a3";
	for (auto &digit : obj.matrix.at(obj.matrix.size() - 1))
		os << digit << "\t";
	os << "\u23a6\n";

	return os;
}
}
