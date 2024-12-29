#ifndef TEMPLATE_TVECTOR
#define TEMPLATE_TVECTOR

#include <iostream>
#include <assert.h>

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

	for (int i = 0; i < m_size; i++)
		m_vector[i] = otherObject.m_vector[i];

}

template <typename Type>
TVector<Type>::~TVector()
{
	delete[]m_vector;
}

template <typename Type>
Type& TVector<Type>::operator [] (const int index) const
{
	assert(index >= 0 && index < m_size);
	return m_vector[index];
}

template <typename Type>
TVector<Type>& TVector<Type>::operator = (const TVector<Type>& object)
{
	if (this == &object) {
		return *this;
	}

	if (this->m_size != object.m_size) {
		delete[] m_vector;

		m_size = object.m_size;
		m_vector = new Type[m_size];

	}

	for (int i = 0; i < m_size; i++) {
		m_vector[i] = object.m_vector[i];
	}

	return *this;

}

template <typename Type>
TVector<Type>& TVector<Type>::operator += (const TVector<Type>& object)
{
	if (m_size != object.m_size) {
		return *this;
	}

	for (int i = 0; i < m_size; i++)
		m_vector[i] += object.m_vector[i];

	return *this;
}

template<typename Type>
void TVector<Type>::setLength(int newSize)
{
	if (m_size = newSize)
		return;
	
	// rewrite existing elements in vector
	int minSize = std::min(m_size, newSize);
	Type* tempVector = new Type[minSize];

	for (int i = 0; i < minSize; i++)
		tempVector[i] = m_vector[i];

	delete[]m_vector;

	m_vector = new Type[newSize]();

	for (int i = 0; i < minSize; i++)
		m_vector[i] = tempVector[i];

	delete[]tempVector;

	m_size = newSize;
}

template <typename Type>
std::ostream& operator << (std::ostream& stream, const TVector<Type>& object)
{
	stream << "[ ";
	for (int i = 0; i < object.m_size; i++)
		stream << object[i] << " ";
	stream << "]";

	return stream;
}

template <typename Type>
std::istream& operator >> (std::istream& stream, TVector<Type>& object)
{
	for (int i = 0; i < object.m_size; i++) {
		std::cout << "[" << i << "] = ";
		stream >> object[i];
	}

	return stream;
}

#endif