#include <iostream>
#include <random>

#include "CStr.h"

char* CStr::generateString(const size_t length)
{
	char* tempStr = new char[length + 1];

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(97, 122);

	for (int i = 0; i < length; i++)
		tempStr[i] = char(dist(gen));

	tempStr[length] = '\0';

	return tempStr;
}

CStr::CStr()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 20);

	size_t length = dist(gen);
	m_string = generateString(length);
}

CStr::CStr(size_t& length)
{
	// task condition "length <= 20 symbols"
	if (length > 20) {
		std::cerr << "CStr::CStr(size_t& length) : length >= 20, value changed to 20" << std::endl;
		length = 20;
	}
	m_string = generateString(length);
}

CStr::CStr(const char* sourceString)
{
	m_string = new char[strlen(sourceString) + 1];
	strcpy(m_string, sourceString);
}

CStr::CStr(const CStr& otherObject)
{
	m_string = new char(strlen(otherObject.m_string) + 1 );
	strcpy(m_string, otherObject.m_string);

}


CStr::~CStr()
{
	delete[] m_string;
}
