/**
 *    Description:  
 *        Version:  1.0
 *        Created:  27/10/2015 10:41:44
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Kyle Robbertze (kr), paddatrapper@gmail.com
 */

#include <stdlib.h>
#include <iostream>
#include "libmatrix/matrix.h"

/**
 * Main
 */
int main(int argc, char *argv[])
{
	libmatrix::Matrix::matrix_t vector_a = {
		{1.0, 0.0, 0.0},
		{0.0, 1.0, 0.0},
		{0.0, 0.0, 1.0}
	};
	libmatrix::Matrix a(vector_a);
	libmatrix::Matrix::matrix_t vector_b = {
		{1.0, 4.0, 1.5},
		{0.6, 6.0, 8.0},
		{0.0, 0.0, 1.0}
	};
	libmatrix::Matrix b(vector_b);
	std::cout << "Addition:\n";
	std::cout << (a + b);
	std::cout << "Subtraction:\n";
	std::cout << (a - b);
	std::cout << "Multiplication by constant:\n";
	std::cout << (2 * a);
	return EXIT_SUCCESS;
}

