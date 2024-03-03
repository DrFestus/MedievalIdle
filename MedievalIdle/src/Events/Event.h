// Event.h
#pragma once

class Event {
public:
    virtual ~Event() = default;
    // You can add common event properties or methods here
};

class ResourceChangeEvent : public Event {
public:
    int amountChanged;
    std::string resourceName;

    ResourceChangeEvent(int amount, std::string name) : amountChanged(amount), resourceName(std::move(name)) {}
};

class ButtonClickedEvent : public Event {
public:
    ButtonClickedEvent() = default;
};
