#include <iostream>
#include <random>

#include "CStr.h"

int main() {
	char string[6]{'m','e','l','o','n'};
	
	CStr testObject(string);

	std::cout << testObject << std::endl;

	std::cin >> testObject;

	std::cout << testObject << std::endl;

	std::cout << "First symbol : " << testObject[0] << std::endl;

	return 0;
}