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