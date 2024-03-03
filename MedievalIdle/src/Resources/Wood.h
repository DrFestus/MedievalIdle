// Wood.h
#include "Resource.h"

class Wood : public Resource {
public:
    Wood(int initialAmount, int productionRate)
        : Resource("Wood", initialAmount, productionRate) {}
    // Implement any wood-specific behaviors
};