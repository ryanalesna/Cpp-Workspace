#include "List.h"
#include "Dictionary.h"
#include "Object_Factory.h"
#include "Windows.h"
#include <stdio.h>
#include <string>

unsigned int hash(const char* string);
int main() 
{
	/*Dictionary<int> dict;
	std::string s = "hello";
	const char* c = s.c_str();
	hash("hello");
	printf("%i \n", hash(c));
	printf("%i \n", hash(c));
	printf("%i \n", hash(c));

	dict.add("hello", 0);
	dict.lookup("hello");
	dict.loopThrough();
	system("pause");

	const int N = 59;
	DictionaryPair<int> m_buckets[N];
	unsigned int hashCode = hash(c);
	hashCode = hashCode % N;
	//m_buckets + hashCode;
	*/


	Vehicle* pcar = createVehicleByName(Car, "Ryan's Car");
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
