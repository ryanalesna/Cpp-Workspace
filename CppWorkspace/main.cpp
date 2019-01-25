#include "List.h"
#include "Dictionary.h"
#include "Object_Factory.h"
#include "Windows.h"
#include <stdio.h>
#include <string>
#include "Assertions.h"
#include "Ptr.hpp"

class foobar
{
public:
	foobar() {
		printf("Constructed\n");
	}

	~foobar()
	{
		printf("DESTROYED\n");
	}
};

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
	

	const int N = 59;
	DictionaryPair<int> m_buckets[N];
	unsigned int hashCode = hash(c);
	hashCode = hashCode % N;
	//m_buckets + hashCode;
	*/
	/*Vehicle* pCar = createVehicleByName("car", "Ryan's Car");
	if (pCar)
	{
		printf("%s", pCar->getTypeOfVehicle().c_str());
		printf("\n");
		printf("%s", pCar->getNameOfVehicle().c_str());
		printf("\n");
	}
	
	Vehicle* pTruck = createVehicleByName("semi-truck", "Ryan's Truck");
	if (pTruck)
	{
		
		printf("%s", pTruck->getTypeOfVehicle().c_str());
		printf("\n");
		printf("%s", pTruck->getNameOfVehicle().c_str());
		printf("\n");
	}
	*/
	
	try {
		List<int> list;
		printf("%i", list.remove(0));
	}
	catch (Exception* e)
	{
		printf(e->getUnified().c_str());
		delete e;
	}

	system("pause");



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
