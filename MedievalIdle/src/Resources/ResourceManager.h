// ResourceManager.h
#pragma once

#include "Core/Core.h" // Include Core.h for smart pointer definitions
#include "Resources/Resource.h"
#include "Resources/Wood.h"
#include "Resources/Stone.h"
#include "Resources/Food.h"
#include <map>
#include <string>

class ResourceManager {
private:
    std::map<std::string, Ref<Resource>> resources;

public:
    ResourceManager() {
        // Initialize resources with their starting values and production rates
        resources["Wood"] = CreateRef<Wood>(100, 5); // Example values using smart pointers
        resources["Stone"] = CreateRef<Stone>(50, 2);
        resources["Food"] = CreateRef<Food>(100, 2);
        // Add more as needed
    }

    void produceResources(int time) {
        for (auto& [name, resource] : resources) {
            resource->produce(time);
        }
    }

    void consumeResource(const std::string& name, int qty) {
        if (resources.find(name) != resources.end()) {
            resources[name]->consume(qty);
        }
    }

    int getResourceAmount(const std::string& name) const {
        if (resources.find(name) != resources.end()) {
            return resources.at(name)->getAmount();
        }
        return 0; // Resource not found
    }

    // Method to get a const reference to the resources map
    const std::map<std::string, Ref<Resource>>& getResources() const {
        return resources;
    }
};
