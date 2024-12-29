#ifndef ARE_TEMPLATE_VECTOR_METHODS_DEFINED
#define ARE_TEMPLATE_VECTOR_METHODS_DEFINED

#include <iostream>

#include "TVector.h"

template <typename Type>
TVector<Type>::TVector(int size)
	: m_size(abs(size))
{
	m_vector = new Type[m_size]();
}

template <typename Type>
TVector<Type>::TVector(const TVector<Type>& otherObject)
	: m_size(otherObject.m_size)
{
	m_vector = new Type[m_size];

	for (int i = 0 ; i < m_size; i++)
		m_vector[i] = otherObject.m_vector[i];

}

template <typename Type>
TVector<Type>::~TVector()
{
	delete[]m_vector;
}

#endif