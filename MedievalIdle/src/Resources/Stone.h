// Stone.h
#include "Resource.h"

class Stone : public Resource {
public:
    Stone(int initialAmount, int productionRate)
        : Resource("Stone", initialAmount, productionRate) {}
    // Implement any stone-specific behaviors
};
