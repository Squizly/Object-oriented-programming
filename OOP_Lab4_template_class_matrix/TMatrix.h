#pragma once

#ifndef ARE_TEMPLATE_MATRIX_DECLARED
#define ARE_TEMPLATE_MATRIX_DECLARED

#include "../OOP_Lab3_template_class_vector/TVector.h"

template <typename Type>
class TMatrix {
public:
	TMatrix( const int row = 1, const int column = 1 );
	TMatrix( const TMatrix<Type>& );
	~TMatrix();


private:
	TVector<Type>* m_matrix = nullptr;
	int m_row = 0;
	int m_column = 0;

};

#include "TMatrix.cpp"

#endif //!ARE_TEMPLATE_VECTOR_DECLARED
