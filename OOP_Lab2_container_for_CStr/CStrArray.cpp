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

//bubble sort
void CStrArray::sort_by_content() const
{
	for (int i = 0; i < m_size - 1; i++) {

		for (int j = 0; j < m_size - 1 - i; j++) {

			if (m_array[j]->operator > (*m_array[j + 1]))
				std::swap(m_array[j], m_array[j + 1]);

		}
	}
}

void CStrArray::sort_by_length_string() const
{
	for (int i = 0; i < m_size - 1; i++) {

		for (int j = 0; j < m_size - 1 - i; j++) {
			
			if (m_array[j]->getLength() > m_array[j + 1]->getLength())
				std::swap(m_array[j], m_array[j + 1]);
		
		}
	}
}

bool CStrArray::check_sort_content()
{
	for (int i = 0; i < m_size - 1; i++) {
		
		if (m_array[i]->operator>(*m_array[i + 1]))
			return false;
	
	}

	return true;
}

std::ostream& operator << (std::ostream& stream, const CStrArray& object)
{
	stream << std::endl;
	for (int i = 0; i < object.m_size; i++)
		stream << object[i] << " ";
	return stream;
}
