#pragma once

#ifndef ARE_TEMPLATE_VECTOR_DECLARED
#define ARE_TEMPLATE_VECTOR_DECLARED

template <typename Type>
class TVector
{
	template <typename Type>
	friend std::ostream& operator << (std::ostream& stream, const TVector<Type>& object);
	
	template <typename Type>
	friend std::istream& operator >> (std::istream& stream, TVector<Type>& object);

public:

	TVector( int size = 1 );
	TVector( const TVector<Type>& );
	~TVector();

	Type& operator [] ( const int ) const;
	TVector<Type>& operator = ( const TVector<Type>& );

	TVector<Type>& operator += ( const TVector<Type>& );

	void setLength( int );

private:
	Type* m_vector = nullptr;
	int m_size = 0;
};

template <typename Type>
std::ostream& operator << (std::ostream& stream, const TVector<Type>& object);

template <typename Type>
std::istream& operator >> (std::istream& stream, TVector<Type>& object);

#include "TVector.cpp"

#endif //!ARE_TEMPLATE_VECTOR_DECLARED