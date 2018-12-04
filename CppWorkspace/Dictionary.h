#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "List.h"
#include <string>

template<class T>
class DictionaryPair
{
private:
	T m_value;
	char* m_string = NULL;
public: 
	//default constructor
	DictionaryPair() { }
	//overloaded constructor
	DictionaryPair(std::string string, T value)
	{
		const char* c = string.c_str();
		int length = strlen(c);
		m_string = new char[length + 1];
		strcpy_s (m_string, length + 1, c);
		m_string[length] = 0;
	}
	//gets value
	T GetValue()
	{
		return m_value;
	}
	//tests if the strings are equal
	bool StringEquals(const char* string)
	{
		return !strcmp(string, m_string);
	}
};

//Dictionary Class Template
template<class T, unsigned int N = 59>
class Dictionary
{
private:
	List<DictionaryPair<T>> m_buckets[N];
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
	DictionaryPair<T>* findPair(const char* string) 
	{
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
	void add(std::string string, T key)
	{
		const char* c = string.c_str();
		findBucket(c)->push(DictionaryPair<T>(string, key));
	}
	T lookup(std::string string)
	{
		const char* c = string.c_str();
		return findPair(c)->GetValue();
	}
	T remove(std::string string)
	{
		const char* c = string.c_str();
		int index = 0;
		DictionaryPair<T>* pair = findPair(c);
		List<DictionaryPair<T>>* bucket = findBucket(c);
		for (int i = 0; i < bucket->length(); i++) 
		{
			if (bucket->getPtr(i) == pair)
			{
				index = i;
				break;
			}
		}
		T removed = bucket->remove(index).GetValue();
		return removed;
	}
	bool contains(std::string string)
	{
		const char* c = string.c_str();
		bool exists = false;
		DictionaryPair<T>* pair = findPair(c);
		List<DictionaryPair<T>>* bucket = findBucket(c);
		for (int i = 0; i < bucket->length(); i++)
		{
			if (bucket->getPtr(i) == pair)
			{
				exists = true;
				break;
			}
		}
		return exists;
	}
};

#endif // DICTIONARY_H
