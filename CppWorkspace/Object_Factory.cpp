#include "Object_Factory.h"

Dictionary<GenericVehicleFactory*> g_mVehicleFactories;

class Car : public Vehicle
{
public:
	Car() { };

};
class SemiTruck : public Vehicle
{ };

LINK_CLASS_TO_NAME(Car, car);
LINK_CLASS_TO_NAME(SemiTruck, semi-truck);

Vehicle* createVehicleByName(const char* pszTypeName, const char* pszInstanceName)
{
	GenericVehicleFactory* pFactory = g_mVehicleFactories.lookup(pszTypeName);
	Vehicle* pVehicle = pFactory ? pFactory->create() : NULL;
	if (pVehicle) {
		pVehicle->setName(pszInstanceName);
		pVehicle->setType(pszTypeName);
	}
	return pVehicle;
	
}