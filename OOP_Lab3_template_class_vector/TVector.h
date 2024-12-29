#pragma once

#ifndef ARE_TEMPLATE_VECTOR_DECLARED
#define ARE_TEMPLATE_VECTOR_DECLARED

template <typename Type>
class TVector
{
	friend std::ostream& operator << ( std::ostream&, const TVector<Type>& );
	friend std::istream& operator >> ( std::istream&, TVector<Type>& );

public:
	TVector(int size = 1);
	TVector(const TVector<Type>&);
	~TVector();

private:
	Type* m_vector = nullptr;
	int m_size = 0;
};

template <typename Type>
std::ostream& operator << (std::ostream&, const TVector<Type>&);

template <typename Type>
std::istream& operator >> (std::istream&, TVector<Type>&);

#include "TVector.cpp"

#endif //!ARE_TEMPLATE_ARRAY_DECLARED