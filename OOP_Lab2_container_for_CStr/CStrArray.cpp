#include <iostream>
#include <assert.h>

#include "CStrArray.h"

CStrArray::CStrArray(int capacity) : m_capacity(capacity)
{
	assert(m_capacity >= 0);

	m_array = new CStr * [m_capacity];

	for (int i = 0; i < m_capacity; i++)
		m_array[i] = nullptr;
}

CStrArray::~CStrArray()
{
	delete[]m_array;
}

CStrArray* CStrArray::operator += (CStr* object)
{
	if (m_size < m_capacity)
		m_array[m_size++] = object;

	return this;
}

CStr& CStrArray::operator [] (const int index) const
{
	assert(index >= 0 && index <= m_size);
	return *m_array[index];
}


std::ostream& operator << (std::ostream& stream, const CStrArray& object)
{
	stream << std::endl;
	for (int i = 0; i < object.m_size; i++)
		stream << object[i] << " ";
	return stream;
}
