#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "List.h"
#include "string.h"

template<class T>
class DictionaryPair
{
private:
	T m_value;
	char* m_string = NULL;
public: 
	//default constructor
	DictionaryPair()
	{

	}
	//overloaded constructor
	DictionaryPair(const char* string, T value)
	{
		int length = strlen(string);
		m_string = new char[length + 1];
		strcpy(m_string, string);
		m_string[length] = 0;
	}
	//gets value
	T GetValue()
	{
		return m_value;
	}
	//tests if the strings are equal
	bool StringEquals(char* string)
	{
		return !strcmp(string, m_string);
	}

};

//Dictionary Class Template
template<class T, unsigned int N = 59>
class Dictionary
{
private:
	List<DictionaryPair> m_buckets[N];
	//finds the running hash of the string
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
	//Finds the bucket which the string would be in
	List<DictionaryPair<T>>* findBucket(const char* string)
	{
		unsigned int hashCode = hash(string);
		hashCode = hashCode % N;
		return m_buckets + hashCode;
	}

	/* Returns pointer to pair if it exists, NULL otherwise */
	DictionaryPair<T>* findPair(const char* string) {
		List<DictionaryPair<T>>* bucket = findBucket(string);

		DictionaryPair<T>* result = NULL;
		for (int i = 0; i < bucket->length(); i++)
		{
			if (bucket->getPtr(i)->StringEquals(string))
			{
				result = bucket->getPtr(i);
				break;
			}
		}
		return result;
	}
public:
	Dictionary() { }
	add(const* char value, int key)
	{

	}
	T lookup(const char* string)
	{
		return findPair(string)->GetValue();
	}
	remove(const* char value, int key)
	{

	}
};

#endif // DICTIONARY_H
