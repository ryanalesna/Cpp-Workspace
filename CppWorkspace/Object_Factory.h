//Implement CreateVehicleByName Function using correct Dictionary 
//Change constructor in vehicle to set name and set type 

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

	virtual Vehicle* create(const char* type, const char* name)
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
	Vehicle* create(const char* type, const char* name)
	{
		return new T(type, name);
	}
};

class Vehicle
{
	Vehicle() { };
	void setType(const char* type)
	{
		type = m_type;
	}
	void setName(const char* name)
	{
		name = m_name;
	}
private:
	const char* m_type;
	const char* m_name;
public:
	
	virtual void printNameOfVehicle()
	{
		printf(m_name);
	}
	void printTypeOfVehicle()
	{
		printf(m_type);
	}
};

class Car : public Vehicle
{ 
	//Car(type, name) : Vehicle() { };

};
class SemiTruck : public Vehicle
{ };
Vehicle* createVehicleByName(const char* pszTypeName, const char* pszInstanceName)
{
	GenericVehicleFactory* pFactory = g_mVehicleFactories.lookup(pszTypeName);
	Vehicle* pVehicle = pFactory->create(pszTypeName, pszInstanceName);
	return pVehicle;
}





#endif
