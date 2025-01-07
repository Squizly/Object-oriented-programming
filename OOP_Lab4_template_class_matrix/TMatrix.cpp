#ifndef TEMPLATE_TMATRIX
#define TEMPLATE_TMATRIX

#include <iostream>
#include <assert.h>

#include "TMatrix.h"

template <typename Type>
TMatrix<Type>::TMatrix(const int row, const int column)
	: m_row(abs(row)), m_column(abs(column))
{
	m_matrix = new TVector<Type>[row]();
	for (int i = 0; i < row; i++)
		m_matrix[i] = TVector<Type>(column);
}

template <typename Type>
TMatrix<Type>::TMatrix(const TMatrix<Type>& object)
	: m_row(object.m_row), m_column(object.m_column)
{
	m_matrix = new TVector<Type>[m_row]();

	for (int i = 0; i < m_row; i++)
		m_matrix[i] = object.m_matrix[i];
	
}

template <typename Type>
TMatrix<Type>::~TMatrix()
{
	delete[]m_matrix;
}

template <typename Type>
TMatrix<Type>& TMatrix<Type>::operator = ( const TMatrix<Type>& object )
{
	if (m_row == object.m_row && m_column == object.m_column) {

		for (int i = 0; i < m_row; i++)
			m_matrix[i] = object.m_matrix[i];

	}

	return *this;
}

template <typename Type>
TMatrix<Type>& TMatrix<Type>::operator += (const TMatrix<Type>& object)
{
	if (m_row == object.m_row && m_column == object.m_column) {

		for (int i = 0; i < m_row; i++)
			m_matrix[i] += object.m_matrix[i];

	}

	return *this;
}

template <typename Type>
TVector<Type>& TMatrix<Type>::operator [] (const int index) const
{
	assert(index < m_row);
	return m_matrix[abs(index)];
}

template <typename Type>
std::ostream& operator << (std::ostream& stream, const TMatrix<Type>& object)
{
	for (int i = 0; i < object.m_row; i++) {
		stream << object[i] << std::endl;
	}

	return stream;
}

template <typename Type>
std::istream& operator >> (std::istream& stream, TMatrix<Type>& object)
{
	for (int i = 0; i < object.m_row; i++)
		for (int j = 0; j < object.m_column; j++) {

			std::cout << "\n[" << i << "][" << j << "] = ";
			std::cin >> object[i][j];

		}

	return stream;
}


#endif