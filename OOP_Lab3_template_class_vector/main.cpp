#include <iostream>

#include "TVector.h"

int main() {
	std::cout << "Hello world!" << std::endl;

	TVector<int> object(5);
	std::cin >> object;
	std::cout << object << std::endl;

	object.setLength(6);
	std::cout << object << std::endl;
	object.setLength(2);
	std::cout << object << std::endl;
	object.setLength(5);
	std::cout << object << std::endl;

	return 0;
}