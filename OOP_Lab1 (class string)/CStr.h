#pragma once

class CStr
{
	char* generateString(size_t length);
public:

	CStr();
	CStr(size_t& length);
	CStr(const char* sourceString);
	CStr(const CStr& otherObject);
	~CStr();
	
	void tempPrint()
	{
		for (int i = 0; i < strlen(m_string); i++)
			std::cout << m_string[i];
		std::cout << std::endl;
	}

private:
	char* m_string = nullptr;
};