// EventDispatcher.h
#pragma once

#include "Event.h"
#include "Core/Log.h" // Adjust this include path to wherever your logger is defined
#include <functional>
#include <list>
#include <typeindex>
#include <unordered_map>

class EventDispatcher {
    using EventCallback = std::function<void(const Event&)>;
    std::unordered_map<std::type_index, std::list<EventCallback>> listeners;

public:
    template<typename EventType>
    void subscribe(const EventCallback& callback) {
        listeners[typeid(EventType)].push_back(callback);
    }

    template<typename EventType>
    void dispatch(const EventType& event) {
        auto& callbacks = listeners[typeid(EventType)];
        if (!callbacks.empty()) {
            LOG_INFO("Dispatching event: {}", typeid(EventType).name()); // Log the event type being dispatched
        }
        for (auto& callback : callbacks) {
            callback(event);
        }
    }
};
