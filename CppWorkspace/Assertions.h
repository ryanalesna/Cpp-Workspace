#ifndef ASSERTIONS_H
#define ASSERTIONS_H
#include "string"
#include <cstdarg>

class Exception
{
public:
	std::string m_lineNumber;
	std::string m_functionSignature;
	std::string m_condition;
	std::string m_description;

	Exception(std::string lineNumber, std::string functionSignature, std::string condition)
	{
		m_lineNumber = lineNumber;
		m_functionSignature = functionSignature;
		m_condition = condition;
	}
	static void thrw(std::string lineNumber, std::string functionSignature, std::string condition, const char* descFormat, ...)
	{
		va_list args;
		va_start(args, descFormat);
		char buffer[512];
		vsnprintf(buffer, 512, descFormat, args);
		Exception* pException = new Exception(lineNumber, functionSignature, condition);
		pException->m_description = buffer;
		va_end(args);
		throw pException;
	}

	std::string getUnified() const
	{
		std::string unified = m_lineNumber + " " + m_functionSignature + " " + m_condition + " " + m_description;
		return unified;
	}

};

//__FILE__ to get the current file name

#define STRINGIFY2(term) #term
#define STRINGIFY(term) STRINGIFY2(term)

#define ASSERT(condition, descFormat, ...) \
	if(!(condition)) { \
		Exception::thrw(STRINGIFY(__LINE__), __FUNCSIG__, #condition, descFormat, __VA_ARGS__); \
	}

#endif
