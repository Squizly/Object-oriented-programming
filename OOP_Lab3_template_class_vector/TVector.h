#pragma once

template <typename Type>
class TVector
{
	friend std::ostream& operator << (std::ostream& stream, const TVector<Type>& object);
	friend std::istream& operator >> (std::istream& stream, TVector<Type>& object);

public:

	TVector(int size = 1);
	TVector(const TVector<Type>&);
	~TVector();


private:
	Type* m_vector = nullptr;
	int m_size = 0;
};

template <typename Type>
std::ostream& operator << (std::ostream& stream, const TVector<Type>& object);

template <typename Type>
std::istream& operator >> (std::istream& stream, TVector<Type>& object);
