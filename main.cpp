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
#include "matrix.h"

/**
 * Main
 */
int main(int argc, char *argv[])
{
	Matrix::matrix_t vector = {
		{1.0, 0.0, 0.0},
		{0.0, 1.0, 0.0},
		{0.0, 0.0, 1.0}
	};
	Matrix a(vector);
	std::cout << (a + a + a + a);
	return EXIT_SUCCESS;
}

