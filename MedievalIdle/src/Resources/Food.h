#pragma once

#include "Resource.h"

class Food : public Resource {

public:
	Food(int initialAmount, int productionRate)
		: Resource("Food", initialAmount, productionRate) {}
private:


};
