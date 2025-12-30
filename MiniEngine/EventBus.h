#pragma once
#include <functional>
#include <vector>
#include <unordered_map>
#include <typeindex>

#include "Event.h"

class EventBus
{
public:
    template <typename EventType>
    using Handler = std::function<void(const EventType &)>;

    template <typename EventType>
    void subscribe(Handler<EventType> handler)
    {
        auto wrapper = [handler](const Event &event)
        {
            handler(static_cast<const EventType &>(event));
        };
        handlers[typeid(EventType)].push_back(wrapper);
    }

    template <typename EventType>
    void emit(const EventType &event)
    {
        auto it = handlers.find(typeid(EventType));
        if (it != handlers.end())
        {
            for (auto &handler : it->second)
            {
                handler(event);
            }
        }
    }

private:
    std::unordered_map<
        std::type_index,
        std::vector<std::function<void(const Event &)>>>
        handlers;
};
