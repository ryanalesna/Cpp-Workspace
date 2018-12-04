//#include "List.h"
//#include "Dictionary.h"
#include "Windows.h"
#include <stdio.h>
#include "Dictionary.h"
#include <string>

unsigned int hash(const char* string);
int main() 
{
	std::string s = "hello";
	const char* c = s.c_str();
	hash("hello");
	printf("%i \n", hash(c));
	printf("%i \n", hash(c));
	printf("%i \n", hash(c));
	system("pause");

	const int N = 59;
	DictionaryPair<int> m_buckets[N];
	unsigned int hashCode = hash(c);
	hashCode = hashCode % N;
	m_buckets + hashCode;
}
unsigned int hash(const char* string)
	{
		char c = string[0];
		int i = 0;
		unsigned int runningHash = c;
		while (c)
		{
			runningHash = runningHash * c;
			c = string[++i];
		}
		return runningHash;


	
	}
