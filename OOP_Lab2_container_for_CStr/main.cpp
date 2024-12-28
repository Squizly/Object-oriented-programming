#include <iostream>

#include "CStrArray.h"

int main(void) {
	CStrArray cont(5);

	CStr first;
	CStr second;
	CStr third;
	CStr thourd;

	cont += &first;
	cont += &second;
	cont += &third;
	cont += &thourd;

	std::cout << cont << std::endl;

	cont.sort_by_content();

	if (cont.check_sort_content())
		std::cout << "Array is sorted by content." << std::endl;

	else
		std::cout << "Array has not sorted element" << std::endl;

	return 0;
}