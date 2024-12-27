#pragma once

#include "../OOP_Lab1 (class string)/CStr.h"

class CStrArray
{
	CStrArray(int length = 0);
	~CStrArray();


private:
	CStr** m_array = nullptr;
	int m_capacity = 0; // source length array
	int m_size = 0; // value non-zero elements in array
};