#pragma once

class CStr
{
	friend std::ostream& operator << (std::ostream& stream, const CStr& object);
	friend std::istream& operator >> (std::istream& stream, CStr& object);

public:

	CStr();
	CStr(int length);
	CStr(const char* arr);
	CStr(const CStr& otherObject);
	~CStr();

	CStr& operator = (const CStr& );
	CStr& operator = (const char* );

	CStr operator + (const CStr& ) const;
	CStr& operator += (const CStr& );
	 
	bool operator > (const CStr& ) const;
	bool operator < (const CStr& ) const;
	bool operator >= (const CStr& ) const;
	bool operator <= (const CStr& ) const;

	char& operator [] (const int& index) const;

	int getLength() const;

private:
	char* generateString(int length);

	char* m_string = nullptr;
};

std::ostream& operator << (std::ostream& stream, const CStr& object);

std::istream& operator >> (std::istream& stream, CStr& object);