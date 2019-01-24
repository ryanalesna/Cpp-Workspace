//Implement CreateVehicleByName Function using correct Dictionary 

#ifndef OBJECT_FACTORY_H
#define OBJECT_FACTORY_H
#define LINK_CLASS_TO_NAME(Class, Name) SpecificVehicleFactory<Class> g_##Class##Factory(#Name);  
#include "Dictionary.h"

class GenericVehicleFactory;
extern Dictionary<GenericVehicleFactory*> g_mVehicleFactories;
class Vehicle;


class GenericVehicleFactory
{
public:
	GenericVehicleFactory(const char* type)
	{
		const char* object_Type = type;
		g_mVehicleFactories.add(type, this);
	}

	virtual Vehicle* create()
	{
		return NULL;
	}
};

template <class T>
class SpecificVehicleFactory : GenericVehicleFactory
{
public:

	SpecificVehicleFactory(const char* type) : GenericVehicleFactory(type) {}
	const char* object_Type;
	Vehicle* create()
	{
		T* result = new T();
		return result;
	}
};

class Vehicle
{
private:
	
public:
	std::string m_type;
	std::string m_name;

	Vehicle() { };

	virtual std::string getNameOfVehicle()
	{
		return m_name.c_str();
	}
	std::string getTypeOfVehicle()
	{
		return m_type.c_str();
	}
	void setType(const char* type)
	{
		m_type = type;
		
	}
	void setName(const char* name)
	{
		m_name = name;
	}
};



Vehicle* createVehicleByName(const char* pszTypeName, const char* pszInstanceName);


#endif
