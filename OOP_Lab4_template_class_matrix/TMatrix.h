#pragma once

#ifndef ARE_TEMPLATE_MATRIX_DECLARED
#define ARE_TEMPLATE_MATRIX_DECLARED

#include "../OOP_Lab3_template_class_vector/TVector.h"

template <typename Type>
class TMatrix {

	template <typename Type>
	friend std::ostream& operator << (std::ostream& stream, const TMatrix<Type>& object);

	template <typename Type>
	friend std::istream& operator >> (std::istream& stream, TMatrix<Type>& object);

public:
	TMatrix( const int row = 1, const int column = 1 );
	TMatrix( const TMatrix<Type>& );
	~TMatrix();

	TMatrix<Type>& operator = ( const TMatrix<Type>& );
	TMatrix<Type>& operator += ( const TMatrix<Type>& );
	TVector<Type>& operator [] ( const int ) const;

private:
	TVector<Type>* m_matrix = nullptr;
	int m_row = 0;
	int m_column = 0;

};

template <typename Type>
std::ostream& operator << (std::ostream& stream, const TMatrix<Type>& object);

template <typename Type>
std::istream& operator >> (std::istream& stream, TMatrix<Type>& object);

#include "TMatrix.cpp"

#endif //!ARE_TEMPLATE_MATRIX_DECLARED
