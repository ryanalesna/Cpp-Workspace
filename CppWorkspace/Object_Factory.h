#ifndef OBJECT_FACTORY_H
#define OBJECT_FACTORY_H

class Vehicle
{
	char* type;
	char* name;
public:
	void printNameOfVehicle(char* type)
	{
		printf(name);
	}
	void printTypeOfVehicle()
	{
		printf(type);
	}
};
class Car : Vehicle
{

};

class SemiTruck : Vehicle
{

};
Vehicle* createVehicleByName(const char* pszTypeName, const char* pszInstanceName)
{
	
}


#endif