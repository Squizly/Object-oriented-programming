#pragma once

#include "../OOP_Lab1 (class string)/CStr.h"

class CStrArray
{
	friend std::ostream& operator << ( std::ostream&, const CStrArray& );

public:
	CStrArray(int capacity = 0);
	~CStrArray();

	CStrArray* operator += ( CStr* );
	CStr& operator [] ( const int ) const;

	void sort_by_length_string() const;
	void sort_by_content() const;

	bool check_sort_content();

private:
	CStr** m_array = nullptr;
	int m_capacity = 0; // source length array
	int m_size = 0; // value non-zero elements in array
};

std::ostream& operator << ( std::ostream&, const CStrArray& );
