/**
 *    Description:  A Matrix
 *        Version:  1.0
 *        Created:  27/10/2015 10:13:26
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Kyle Robbertze (kr), paddatrapper@gmail.com
 */
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

/**
 *  A matrix
 */
namespace libmatrix 
{
class Matrix
{
	public:
		typedef std::vector<std::vector<double>> matrix_t;
		// ==================  LIFECYCLE     =======================================
		Matrix(matrix_t matrix);                 // constructor

		// ==================  ACCESSORS     =======================================
		matrix_t getMatrix() const;
		int getNumRows() const;
		int getNumColumns() const;
		double get(int row, int column) const;

		// ==================  MUTATORS      =======================================

		// ==================  OPERATORS     =======================================
		friend Matrix operator+(const Matrix &a, const Matrix &b);
		friend Matrix operator-(const Matrix &a, const Matrix &b);
		friend Matrix operator*(const int &n, const Matrix &a);
		friend Matrix operator*(const Matrix &a, const Matrix &b);
		friend std::ostream& operator<<(std::ostream &os, const Matrix &obj);
	protected:
		// ==================  METHODS       =======================================

		// ==================  DATA MEMBERS  =======================================

	private:
		// ==================  METHODS       =======================================

		// ==================  DATA MEMBERS  =======================================
		const matrix_t matrix;
};
}
#endif
