#include <iostream>

#include "TMatrix.h"

int main() {
	TMatrix<int> object(3,3);

	std::cout << "Source object : \n" << object;

	object[0][0] = 1; object[0][1] = 2; object[0][2] = 3;
	object[1][0] = 4; object[1][1] = 5; object[1][2] = 6;
	object[2][0] = 7; object[2][1] = 8; object[2][2] = 9;

	std::cout << "\nModified object : \n" << object;

	//	Source object :
	//	[0 0 0]
	//	[0 0 0]
	//	[0 0 0]
	//
	//	Modified object :
	//	[1 2 3]
	//	[4 5 6]
	//	[7 8 9]


	return 0;


}