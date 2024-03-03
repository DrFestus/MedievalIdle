// Resource.h
#pragma once

#include <string>

class Resource {
protected:
    std::string name; // For identification, e.g., "Wood", "Stone"
    int amount;       // Current amount of the resource
    int productionRate; // Rate at which the resource is produced or consumed
public:
    Resource(std::string name, int initialAmount, int productionRate)
        : name(name), amount(initialAmount), productionRate(productionRate) {}

    // Accessors
    std::string getName() const { return name; }
    int getAmount() const { return amount; }
    int getProductionRate() const { return productionRate; }

    // Mutators
    void produce(int time) {
        // Example production logic
        amount += productionRate * time; // Modify this based on your game's time system
    }

    void consume(int qty) {
        if (qty <= amount) amount -= qty;
        // Else, handle insufficient resources
    }

    // Add any other general methods relevant to all resources
};
