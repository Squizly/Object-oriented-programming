#include <iostream>
#include <assert.h>
#include <random>

#include "CStr.h"

char* CStr::generateString(const int length)
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

	int length = dist(gen);
	m_string = generateString(length);
}

CStr::CStr(int length)
{
	// task condition "length <= 20 symbols"
	assert(length >= 0 && length <= 20);
	m_string = generateString(length);
}

CStr::CStr(const char* sourceString)
{
	m_string = new char[strlen(sourceString) + 1];
	strcpy(m_string, sourceString);
}

CStr::CStr(const CStr& otherObject)
{
	m_string = new char[strlen(otherObject.m_string) + 1 ];
	strcpy(m_string, otherObject.m_string);
}

CStr::~CStr()
{
	delete[] m_string;
}

CStr& CStr::operator = (const CStr& otherObject)
{
	if (this != &otherObject) {

		delete[]m_string;

		m_string = new char[strlen(otherObject.m_string) + 1];
		strcpy(m_string, otherObject.m_string);
	}

	return *this;
}

CStr& CStr::operator = (const char* string)
{
	if (m_string != string) {

		delete[]m_string;

		m_string = new char[strlen(string) + 1];
		strcpy(m_string, string);
	}

	return *this;
}

CStr CStr::operator + (const CStr& otherObject) const
{
	int newLength = strlen(m_string) + strlen(otherObject.m_string);
	CStr tempString(newLength);

	for (int i = 0, j = 0; i < newLength; i++) {

		if (i < strlen(m_string))
			tempString.m_string[i] = m_string[i];

		else {
			tempString.m_string[i] = otherObject.m_string[j];
			j++;
		}
	}

	return tempString;
}

CStr& CStr::operator += (const CStr& otherObject)
{
	*this = *this + otherObject;

	return *this;
}

bool CStr::operator > (const CStr& otherObject) const
{
	return strcmp(m_string, otherObject.m_string) > 0;
}

bool CStr::operator < (const CStr& otherObject) const
{
	return strcmp(m_string, otherObject.m_string) < 0;
}

bool CStr::operator >= (const CStr& otherObject) const
{
	return strcmp(m_string, otherObject.m_string) >= 0;
}

bool CStr::operator <= (const CStr& otherObject) const
{
	return strcmp(m_string, otherObject.m_string) <= 0;
}

char& CStr::operator [] (const int& index) const
{
	assert(index >= 0 && index < strlen(m_string));
	return m_string[index];
}

int CStr::getLength() const
{
	return strlen(m_string);
}

std::ostream& operator << (std::ostream& stream, const CStr& object)
{
	stream << "[ ";

	for (int i = 0; i < object.getLength(); i++)
		stream << object[i];

	stream << " ]";

	return stream;
}

std::istream& operator >> (std::istream& stream, CStr& object)
{
	char buffer[1024];
	std::cin >> buffer;

	object = buffer;

	return stream;
}

